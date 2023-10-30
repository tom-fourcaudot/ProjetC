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
        char* leafString = malloc((string->size + 1) * sizeof (char));
        memcpy(leafString, string->first_char, string->size);
        *(leafString + string->size) = '\0';
        node->substring = init_string(leafString);
        free(string);
    } else {
        node->rightNeighbour = init_node(cut_string(string), substring_size);
        node->label = string->size;
        node->leftNeighbour = init_node(string, substring_size);
        node->substring = NULL;
    }
    return node;
}