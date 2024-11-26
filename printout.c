#include <stdio.h>
#include "printout.h"
#include "structs.h"
#include <ctype.h>
#include <stdlib.h>

void printNode(struct node nodeP){
    printf("ID: %d\n", nodeP.ID);
    printf("Parent_i: %d\n", nodeP.parent_i);
    printf("Parent: %p\n", nodeP.parent);
    printf("Child1: %d\n", nodeP.child1);
    printf("ChildOne: %p\n", nodeP.childOne);
    printf("Child2: %d\n", nodeP.child2);
    printf("ChildTwo: %p\n\n", nodeP.childTwo);
    return;
}

void help(){
    printf("Helped");
}

void printTree(struct node tree){                                               //prints out the whole tree graphically
    printf("There will be printed tree;)");
}