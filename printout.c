#include <stdio.h>
#include "printout.h"
#include "structs.h"
#include <ctype.h>
#include <stdlib.h>

void printNode(struct node nodeP){
    printf("ID: %d\n", nodeP.ID);
    printf("Parent_i: %d\n", nodeP.parent_i);
    printf("Parent: %x\n", nodeP.parent);
    printf("Child1: %d\n", nodeP.child1);
    printf("ChildOne: %x\n", nodeP.childOne);
    printf("Child2: %d\n", nodeP.child2);
    printf("ChildTwo: %x\n\n", nodeP.childTwo);
    return;
}