#include "filehandler.h"
#include <stdio.h>
#include "structs.h"
#include <ctype.h>
#include <stdlib.h>
#include "printout.h"


int treeAddNode(struct node* root, int parentId, int childId){                          //Creates a new node inside a tree asociated with given parent
    if (findNodeById(root, childId) != NULL){
        return 1;                                                                       //Does not create a node, when given node id is occupied
    }
    else{
        struct node* parent = findNodeById(root, parentId);
        if (parent == NULL){
            return 2;                                                                   //Does not creat a node, when given parent does not exist
        }
        else{
            if (parent->child1 == 0){
                parent->child1 = childId;
                parent->childOne = createNode();
                parent->childOne->ID = childId;
                parent->childOne->parent = parent;
                parent->childOne->parent_i = parentId;
                return 0;
            }
            else if (parent->child2 == 0){
                parent->child2 = childId;
                parent->childTwo = createNode();
                parent->childTwo->ID = childId;
                parent->childTwo->parent = parent;
                parent->childTwo->parent_i = parentId;
                return 0;
            }
            return 3;                                                                   //Does not create a node, when given parent already has to chilren
        }
    }
}


int treeDelNodes(struct node* root);                                                //recursively delete all nodes under given node


int treeHasChildren(struct node* node){                                             //returns number of children given node has
    if (node->child1 != 0 && node->child2 != 0){
        return 2;
    }
    else if (node->child1 != 0 || node->child2 != 0){
        return 1;
    }
    return 0;
}