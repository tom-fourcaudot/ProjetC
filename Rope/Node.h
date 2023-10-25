//
// Created by toum on 10/16/23.
//

#ifndef PROJETC_NODE_H
#define PROJETC_NODE_H

#include "String.h"

typedef struct Node Node;
struct Node{
    unsigned int index;
    unsigned int label;

    Node* leftNeighbour;
    Node* rightNeighbour;
    String* substring;
};

Node* init_node(String* string, const unsigned int* substring_size);
String* cut_string(String* string);
#endif //PROJETC_NODE_H
