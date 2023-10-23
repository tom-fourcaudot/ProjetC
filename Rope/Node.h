//
// Created by toum on 10/16/23.
//

#ifndef PROJETC_NODE_H
#define PROJETC_NODE_H

typedef struct Node Node;
struct Node{
    unsigned int index;
    unsigned int label;

    Node* leftNeighbour;
    Node* rightNeighbour;
    char* substring;
};

Node init_node(char* string, int* substring_size);
#endif //PROJETC_NODE_H
