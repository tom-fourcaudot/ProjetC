//
// Created by toum on 10/16/23.
//

#ifndef PROJETC_ROPE_H
#define PROJETC_ROPE_H

#include "Node.h"

typedef struct Rope Rope;
struct Rope{
    unsigned int MAX_INNER_STRING_SIZE;
    Node root;
};

Rope init_rope(char* string, int substring_size);
void insert_node(Rope* rope, Node* node, int index);

void suppress_node(Rope* rope, int index);
void reequilibrate(Rope* rope);

#endif //PROJETC_ROPE_H
