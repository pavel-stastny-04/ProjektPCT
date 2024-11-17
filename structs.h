#ifndef STRUCTS_H
#define STRUCTS_H

struct node {
    int ID;
    struct node* parent;
    struct node* childOne;
    struct node* childTwo;
};

#endif