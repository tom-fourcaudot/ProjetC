//
// Created by toum on 10/16/23.
//
#include "Rope.h"
#include "Node.h"
#include <stdlib.h>
#include <string.h>

//Intialize a rope with a string and a substring size
//The substring size is the maximum size of a substring
//Return a rope
Rope* init_rope(char *string, int substring_size) {
    char *string2 = strdup(string);
    Rope *rope = malloc(sizeof(Rope));
    rope->MAX_INNER_STRING_SIZE = (unsigned int) substring_size;
    rope->root = *init_node(string2, &(rope->MAX_INNER_STRING_SIZE));
    return rope;
}

//Insert a node in a rope at a given index
void rope_insert_at(Rope *rope, char *string, unsigned int* index) {
    Node *node = get_node_at_index(&rope->root, index);

    if (node != NULL) {
        int newStringLength = strlen(node->substring) + strlen(string);
        char *newString = malloc((newStringLength + 1) * sizeof(char));

        if (newString != NULL) {
            strncpy(newString, node->substring, *index);
            newString[*index] = '\0';
            strcat(newString, string);
            strcat(newString, node->substring + *index);


//            free(node->substring);
            node = init_node(newString, &rope->MAX_INNER_STRING_SIZE);
            int a = 0;
        }
    }
}


// a gauche je retourne left et a droite je retourne right et j'enleve a l'index le label
//Previous cassé et savoir si c'est droite ou gauche pour dire root est droite ou gauche
Node *get_node_at_index(Node *node, unsigned int *index) {
    if (node == NULL){return NULL;}
    if (node->substring != NULL) {
        return node;
    }

    if (*index <= node->label) {
        return get_node_at_index(node->leftNeighbour, index);
    } else {
        *index = *index - node->label;
        return get_node_at_index(node->rightNeighbour, index);
    }
}




