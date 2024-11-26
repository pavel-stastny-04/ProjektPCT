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
    
    int ui = uiAskCommand(root);

    return 0;
}