//
// Created by toum on 10/16/23.
//
#include "Rope.h"
#include "Node.h"

//Intialize a rope with a string and a substring size
//The substring size is the maximum size of a substring
//Return a rope
Rope init_rope(char* string, int substring_size){
    Rope rope;
    rope.MAX_INNER_STRING_SIZE = substring_size;
    rope.root = init_node(string, (unsigned int *) rope.MAX_INNER_STRING_SIZE);
    return rope;
}