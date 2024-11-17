#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include "structs.h"

int loadSaved(struct node* nodes, char path[]);
int saveLoaded(struct node* root, char path[]);

#endif