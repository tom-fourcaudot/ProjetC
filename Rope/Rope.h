//
// Created by toum on 10/16/23.
//

#ifndef PROJETC_ROPE_H
#define PROJETC_ROPE_H

#include "Node.h"

typedef struct Rope Rope;
struct Rope{
    unsigned int MAX_INNER_STRING_SIZE;
    Node *root;
};

Rope * init_rope(char* string, int substring_size);
void free_rope(Rope* rope);
int rope_len(Node* node);
void print_rope(Rope *rope);
Rope* split_rope(Rope* rope, int index);
void insert_at(Rope* rope, char* string, int index);
#endif //PROJETC_ROPE_H
