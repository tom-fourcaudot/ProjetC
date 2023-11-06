//
// Created by toum on 10/16/23.
//

#ifndef PROJETC_NODE_H
#define PROJETC_NODE_H

#include "String.h"

typedef struct Node Node;
struct Node{
    unsigned int label;
    Node* parent;
    Node* leftNeighbour;
    Node* rightNeighbour;
    String* substring;
};

Node* init_node(String* string, const unsigned int* substring_size);
void print_node(Node* node);
int dfs(Node* node);
Node* find_node_at_index(Node* node, int* index);
void split_node(int tmp_index, Node *to_split);
void free_node(Node* node);
#endif //PROJETC_NODE_H
