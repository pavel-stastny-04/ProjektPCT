#ifndef TREE_H
#define TREE_H
#include "structs.h"

int treeAddNode(struct node* root, int parentId, int childId);
int treeDelNodes(struct node* root);
int treeHasChildren(struct node* node);
int treeFindDepth(struct node* node);

#endif