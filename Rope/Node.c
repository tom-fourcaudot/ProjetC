//
// Created by toum on 10/16/23.
//
#include <math.h>
#include "Node.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


Node* init_node(char* string, const unsigned int* substring_size) {
    Node* node = malloc(sizeof (Node));
    unsigned int* string_size = malloc(sizeof (unsigned int));
    *string_size = (unsigned int)strlen(string) ;
    if ( *string_size <= *substring_size) {
        node->label = *string_size;
        node->rightNeighbour = NULL;
        node->leftNeighbour = NULL;
        // TODO Use our string struct
        node->substring = string;
    } else {
        unsigned int left_string_size, right_string_size, nb_full_substring;
        nb_full_substring = (int)(*string_size / *substring_size);
        left_string_size = (unsigned int)ceilf(nb_full_substring/2.0) * *substring_size;
        right_string_size = (int)(nb_full_substring/2) * *substring_size + (*string_size % *substring_size);
        char* left_string = malloc((left_string_size + 1) * sizeof (char));
        char* right_string = malloc((right_string_size +1 ) * sizeof(char));
        strncpy(left_string, string,left_string_size );
        strncpy(right_string, string + (left_string_size), right_string_size);
        left_string[left_string_size] = '\0';
        right_string[right_string_size] = '\0';
        free(string);
        node->leftNeighbour = init_node(left_string, substring_size);
        node->rightNeighbour = init_node(right_string, substring_size);
        node->label = left_string_size;
        node->substring = NULL;
    }
    free(string_size);
    return node;
};