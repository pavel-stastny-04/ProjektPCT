#ifndef STRUCTS_H
#define STRUCTS_H

struct node {                                           //defauld node structure
    int ID;
    int child1;
    int child2;
    int parent_i;
    struct node* parent;
    struct node* childOne;
    struct node* childTwo;
};

struct node* createNode();
void delNode(struct node* node);
struct node* findNodeById(struct node* root, int ID);

#endif