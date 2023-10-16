//
// Created by toum on 10/16/23.
//

#ifndef PROJETC_ROPE_H
#define PROJETC_ROPE_H

#include "Node.h"

typedef struct Rope Rope;
struct Rope{
    const unsigned int MAX_INNER_STRING_SIZE;
    Node root;
};

Rope init_rope(char* string, int substring_size);
#endif //PROJETC_ROPE_H
