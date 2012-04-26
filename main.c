#include "TuringMachine.h"

int main() {
    struct TuringMachine T;
    create(&T);
    regist(&T, 0, '0', 1, 'M', 'R');
    regist(&T, 1, '0', 1, '0', 'R');
    regist(&T, 1, '1', 1, '1', 'R');
    regist(&T, 1, 'M', 2, 'M', 'L');
    regist(&T, 1, 0, 2, 0, 'L');
    regist(&T, 2, '1', 3, 'M', 'L');
    regist(&T, 3, '1', 3, '1', 'L');
    regist(&T, 3, '0', 4, '0', 'L');
    regist(&T, 3, 'M', 5, 'M', 'R');
    regist(&T, 4, '0', 4, '0', 'L');
    regist(&T, 4, 'M', 0, 'M', 'R');
    regist(&T, 5, 'M', 6, 'M', 'R');

    //regist(&T, 0, '0', 0, '0', 'R');
    //regist(&T, 0, '1', 1, '1', 'R');
    //regist(&T, 0, 0, 3, 0, 'R'); 
    //regist(&T, 1, '0', 0, '0', 'R');
    //regist(&T, 1, '1', 2, '0', 'L');
    //regist(&T, 1, 0, 3, 0, 'R');
    //regist(&T, 2, '1', 3, '0', 'R');

    execute(&T, "000111");
    printf("\n");
    execute(&T, "000111");

    return 0;
};
