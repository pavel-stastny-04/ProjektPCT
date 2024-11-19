# include "filehandler.h"
#include <stdio.h>
#include "structs.h"
#include <ctype.h>
#include <ctype.h>
#include <stdlib.h>
#include "printout.h"

int loadSaved(struct node* nodes, char* path){           //loads single node from saved file
    int len = 0;
    FILE *filePtr;
    filePtr = fopen(path, "r");

    if (filePtr == NULL){                                           //stops loading, when the file does not exist
        printf("Nothing is saved for the specified file!");
        return -1;                                                  //the file does not exist, could not load
    }

    else{
        int ID = 0;
        int parent_i = 0;
        int child1 = 0;                                                     //if any child is 0, then do not give pointer to root, but give NULL
        int child2 = 0;
        int ok = fscanf(filePtr, "%d, %d, %d, %d\n", &ID, &parent_i, &child1, &child2);
        nodes->ID = ID;
        nodes->parent_i = parent_i;
        nodes->child1 = child1;
        nodes->child2 = child2;
        struct node* prev = nodes;

        while (ok >= 3){
            len++;
            struct node* newNode = createNode();
            
            if (newNode != NULL){
                ok = fscanf(filePtr, "%d, %d, %d, %d", &ID, &parent_i, &child1, &child2);
                
                newNode->ID = ID;
                newNode->parent = findNodeById(nodes, parent_i);
                newNode->parent_i = parent_i;
                if (newNode->parent->child1 == ID){
                    newNode->parent->childOne = newNode;
                }
                else if (newNode->parent->child2 == ID){
                    newNode->parent->childTwo = newNode;
                }
                else{
                    return -2;                                                  //the file is cursed, cannot load
                }
                newNode->child1 = child1;
                newNode->child2 = child2;
            }
            else {
                return -3;                                                      //not enought memory to load file into
            }
        }
    }

    fclose(filePtr);
    return len;
}

int saveNode(FILE* file, struct node* node){
    if (fprintf(file, "%d, %d, %d, %d\n", node->ID, node->parent_i, node->child1, node->child2) > 0){
        return 0;
    }
    else{
        return 1;                                                               //for some occasion unable to vrite into file
    }
}

int saveNodes(FILE* file, struct node* root, int* cnt){
    if (file == NULL){
        return -1;
    }
    if (root == NULL){
        return 0;                                                               //return 0 when reach NULL pointer
    }
    else{
        if (saveNode(file, root) == 0){
            int ch1 = saveNodes(file, root->childOne, cnt);
            int ch2 = saveNodes(file, root->childTwo, cnt);
            if (ch1 > 0 && ch2 > 0){
                *cnt += 2;
            }
            else if (ch1 > 0 || ch2 > 0){
                *cnt += 1;
            }
            return 1;                                                           //saved successfully
        }
        else{
            return -2;                                                          //unable to save
        }
    }
}

int saveLoaded(struct node* root, char path[]){
    int len = 1;
    FILE *filePtr;
    filePtr = fopen(path, "w");

    int isOK = saveNodes(filePtr, root, &len);
    
    fclose(filePtr);

    if (isOK == 1){
        return len;
    }
    else if (isOK == 0){
        return -1;                                                                  //nothing to save, NULL given
    }
    else{
        return -2;                                                                  //failed to save some node(s)
    }
}
