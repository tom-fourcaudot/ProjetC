//
// Created by toum on 10/16/23.
//
#include "Rope.h"
#include "Node.h"

Rope init_rope(char* string, int substring_size){
    Rope rope;
    rope.MAX_INNER_STRING_SIZE = substring_size;
    rope.root = init_node(string, &substring_size);
    return rope;
}