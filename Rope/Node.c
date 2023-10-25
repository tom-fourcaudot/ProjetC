//
// Created by toum on 10/16/23.
//
#include <math.h>
#include "Node.h"
#include "String.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


Node * init_node(String* string, const unsigned int* substring_size) {
    Node* node = malloc(sizeof (Node));
    if ( string->size <= *substring_size) {
        node->label = string->size;
        node->rightNeighbour = NULL;
        node->leftNeighbour = NULL;
        char* substring = malloc(string->size * sizeof (char));
        memcpy(substring, string->first_char, string->size);
        node->substring = init_string(substring);
    } else {
        node->rightNeighbour = init_node(cut_string(string), substring_size);
        node->leftNeighbour = init_node(string, substring_size);
        node->label = string->size;
        node->substring = NULL;
    }
    return node;
};

String * cut_string(String* string) {
    unsigned int rest = string->size & 1;
    string->size >>= 1;
    String* right_part = malloc(sizeof(String));
    right_part->first_char = string->first_char + string->size;
    right_part->size = string->size + rest;
    return right_part;
}