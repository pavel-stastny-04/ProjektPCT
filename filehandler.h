#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include "structs.h"
#include <stdio.h>

int loadSaved(struct node* nodes, char path[]);
int saveLoaded(struct node* root, char path[]);
int saveNodes(FILE* file, struct node* root, int* cnt);
int saveNode(FILE* file, struct node* node);
void filePrintTree(struct node* tree, char path[]);
void filePrintNode(struct node* node, char path[]);

#endif