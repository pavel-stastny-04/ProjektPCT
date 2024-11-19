# include "filehandler.h"
#include <stdio.h>
#include "structs.h"
#include <ctype.h>
#include <ctype.h>
#include <stdlib.h>

struct node* createNode(){                                      //create a new node in the memory and clears it
    struct node* newNode = malloc(sizeof(struct node));
    if (newNode != NULL){
        newNode->child1=0;
        newNode->child2=0;
        newNode->parent_i=0;
        newNode->childOne=NULL;
        newNode->childTwo=NULL;
        newNode->parent=NULL;
        return newNode;
    }
    else{
        return NULL;
    }
}

void delNode(struct node* node){                                //delete node
    free(node);
}

struct node* findNodeById(struct node* root, int ID){           //finds address of node from given tree of specific ID
    struct node* result = NULL;
    if (root == NULL)
        return NULL;                                            //if pointer is NULL, then return only NULL (NULL has ho atributes)
    else if (root->ID == ID){
        return root;
    }
    else{
        result = findNodeById(root->childOne, ID);
        if (result != NULL){
            return result;
        }
        else{
            result = findNodeById(root->childTwo, ID);
            return result;
        }
    }
}
