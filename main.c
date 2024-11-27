#include <stdio.h>
#include "printout.h"
#include "structs.h"
#include "filehandler.h"
#include <ctype.h>
#include <stdlib.h>
#include "ui.h"

int main(){
    struct node* root = createNode();
    if (root == NULL){
        printf("Not enought memory, exiting application...");
        return 1;                                                       //return error value 1 for insuficient memory
    }
    printf("BinaryTreeSoft v-1.1\nRoot node successfuly initialized.\nStart session by loading saved tree using \"load s [path]\",\nor by adding a node using \"add [parent] [id]\".");

    struct node* current = root;
    char currentPath[2048] = "";
    int saved = 0;
    
    while (uiAskCommand(&root, &current, currentPath, &saved));           //application mainloop

    printf("Exiting application...\n");

    return 0;
}