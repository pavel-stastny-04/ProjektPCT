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

void help(){                                            //prints help info
    printf("BinaryTreeSoft has these commands with their parameters:\n");
    printf("add [parent] [newid]    -> Create a new node\n");
    printf("clear                   -> Clear the console\n");
    printf("del [switch1] [switch2]\n");
    printf("  del c                 -> Delete current node (only when it has no children)\n");
    printf("  del c r               -> Delete current node\n");
    printf("  del i [id]            -> Delete node with specified id\n");
    printf("help                    -> Print out this help\n");
    printf("load s [path]           -> Loads from specified file\n");
    printf("print [switch1] [switch2]\n");
    printf("  print a [*path]       -> print entire tree graphically (* print into given file path)\n");
    printf("  print c [*path]       -> print current node (* print into given file path as append)\n");
    printf("quit                    -> close BinaryTreeSoft (another option is to use \"q\")\n");
    printf("save                    -> save tree into file from which was loaded\n");
    printf("  save e [path]         -> save tree into specified file");
}

void printTree(struct node* tree){                                               //prints out the whole tree graphically
    printf("There will be printed tree;)");
}