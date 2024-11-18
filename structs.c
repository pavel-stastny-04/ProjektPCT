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

struct node* parseTreeToArray(struct node* root, int* len){      //parse structures to array of their pointers
    if (root == NULL && *len <= 0){
        return NULL;                                                          //for NULL input theres nothing to do
    }
    else {
        struct node* list;
        list = (struct node*) malloc(sizeof(struct node*));
        list = root;
        struct node* prewRoot = root;
        struct node* childOne = prewRoot->childOne;
        struct node* childTwo = prewRoot->childTwo;
        while (prewRoot != NULL){
            s;
        }
        



















        list[*len - 1] = *root;
        if (root->childOne != NULL){
            *len += 1;
            int lenSize = *len;
            int testSize = lenSize * sizeof(root);
            printf("ok");
            list = realloc(list, lenSize * sizeof(root));
            if (list == NULL){
                return -2;
            }
            parseTreeToArray(root->childOne, list, len);
        }
        if (root->childTwo != NULL){
            len++;
            list = realloc(list, *len * sizeof(struct node*));
            if (list == NULL){
                return -2;
            }
            parseTreeToArray(root->childTwo, list, len);
        }
        return 0;
    }
}

struct node* createNodeList(){                                      //initialize node pointer list
    return malloc(sizeof(struct node*));
}

void delNodeList(struct node* list){                                //free the memory of the list
    free(list);
}