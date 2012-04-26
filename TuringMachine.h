#ifndef __TURING_MACHINE_H__
#define __TURING_MACHINE_H__

#define MEM_SIZE 1024

struct tuple {
    int state;
    char ch;
    char lr;
};

struct TuringMachine {
    struct tuple * rules[1024][256];
    char memory[MEM_SIZE];
    int location;
    int state;
};

extern void regist(struct TuringMachine * this, int s, char sch, int t, char tch, char lr);
extern int execute(struct TuringMachine * this, const char * s);
extern void create(struct TuringMachine * this);

#endif
