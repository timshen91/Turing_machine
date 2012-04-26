#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "TuringMachine.h"

#define MAP(idx) ((idx) < 0 ? (-(idx)) * 2 - 1 : (idx) * 2)
static void set(char * memory, int idx, char ch) {
    memory[MAP(idx)] = ch;
};

static char get(const char * memory, int idx) {
    return memory[MAP(idx)];
};
#undef MAP

static void dump(const struct TuringMachine * this) {
    printf("%d: ", this->location);
    int i;
    for (i = 0; i < 20; i++) {
        printf("%c ", get(this->memory, i));
    }
    printf("\n");
};

void regist(struct TuringMachine * this, int s, char sch, int t, char tch, char lr) {
    free(this->rules[s][sch]);
    this->rules[s][sch] = malloc(sizeof(struct tuple));
    this->rules[s][sch]->state = t;
    this->rules[s][sch]->ch = tch;
    this->rules[s][sch]->lr = lr;
};

int execute(struct TuringMachine * this, const char * s) {
    this->location = 0;
    this->state = 0;
    memset(this->memory, 0, MEM_SIZE);
    int i;
    for (i = 0; *s != '\0'; i++, s++) {
        set(this->memory, i, *s);
    }
    while (1) {
        dump(this);
        char chNow = get(this->memory, this->location);
        struct tuple * rule;
        if ((rule = this->rules[this->state][chNow])) {
            set(this->memory, this->location, rule->ch);
            this->state = rule->state;
            if (rule->lr == 'L') {
                this->location--;
            } else if (rule->lr == 'R') {
                this->location++;
            } else {
                printf("error\n");
                exit(1);
            }
        } else {
            printf("halt\n");
            break;
        }
    }
    return this->state;
};

void create(struct TuringMachine * this) {
    memset(this, 0, sizeof(struct TuringMachine));
};
