#include <stdio.h>
#include "printout.h"
#include "structs.h"
#include "filehandler.h"

int main(){
    printf("Hello, World!\n\n");
    printNum(5);

    struct node s1;
    s1.ID = 2;

    struct node s2;
    s2.ID = 1;
    s2.childOne = &s1;
    s1.parent = &s2;

    printf("%d\n", s1.ID);
    printf("%x\n", s1.parent);
    printf("%x\n", s1.childOne);
    printf("%x\n", s1.childTwo);
    printf("%d\n", s2.ID);
    printf("%x\n", s2.parent);
    printf("%x\n", s2.childOne);
    printf("%x\n", s2.childTwo);
    

    return 0;
}