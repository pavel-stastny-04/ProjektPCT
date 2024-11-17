#include <stdio.h>
#include "printout.h"
#include "structs.h"
#include "filehandler.h"
#include <ctype.h>
#include <stdlib.h>

int main(){
    struct node* root = createNode();
    if (root == NULL){
        printf("Not enought memory, exiting application...");
        return 1;                                                       //return error value 1 for insuficient memory
    }
    
    int nodesLen = loadSaved(root, "/media/pasta/SCHOOL/VUT/2024-2025/Winter/PC1T/ProjektPCT/test.txt");
    if (nodesLen == -1){
        printf("Error reading file: No such file");
    } 
    else if (nodesLen == -2){
        printf("Error reading file: File cursed");
    }
    else if (nodesLen == -3){
        printf("Error reading file: Insufficient memory");
    }
    else{
        printf("Succesfuly loaded %d nodes.", nodesLen);
    }

    return 0;
}