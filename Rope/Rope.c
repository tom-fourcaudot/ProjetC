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
    Node *parentNode = NULL;
    bool isLeft = false;
    Node *node = get_node_at_index(&rope->root, index, &parentNode, &isLeft);

    if (node != NULL) {
        int newStringLength = strlen(node->substring) + strlen(string);
        char *newString = malloc((newStringLength + 1) * sizeof(char));

        if (newString != NULL) {
            strncpy(newString, node->substring, *index);
            newString[*index] = '\0';
            strcat(newString, string);
            strcat(newString, node->substring + *index);


//            free(node->substring);
            Node* nodeAdd = init_node(newString, &rope->MAX_INNER_STRING_SIZE);
            if (isLeft) {
                parentNode->leftNeighbour = nodeAdd;
            } else {
                parentNode->rightNeighbour = nodeAdd;
            }
        }
    }
}


Node *get_node_at_index(Node *node, unsigned int *index, Node **parentNode, bool* isLeft) {
    if (node == NULL){return NULL;}
    if (node->substring != NULL) {
        *parentNode = *parentNode;
        return node;
    }

    if (*index <= node->label) {
        *parentNode = node;
        *isLeft = true;
        return get_node_at_index(node->leftNeighbour, index, parentNode, isLeft);
    } else {
        *index = *index - node->label;
        *parentNode = node;
        *isLeft = false;
        return get_node_at_index(node->rightNeighbour, index, parentNode, isLeft);
    }
}


//Delete a char at a given index
void delete_char_at(Rope* rope, unsigned int* index, unsigned int* length){
}

int dfs(Node* node) {
    if (node == NULL) {
        return 0;
    }

    return dfs(node->leftNeighbour) + dfs(node->rightNeighbour) + 1;
}





