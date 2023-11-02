//
// Created by toum on 10/16/23.
//
#include "Rope.h"
#include "Node.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//Initialize a rope with a string and a substring size
//The substring size is the maximum size of a substring
//Return a rope
Rope* init_rope(char* string, int substring_size){
    char* tmp = strdup(string);
    String *string_struct = init_string(tmp);
    Rope* rope = malloc(sizeof (Rope));
    rope->MAX_INNER_STRING_SIZE = (unsigned int)substring_size;
    rope->root = init_node(string_struct, &(rope->MAX_INNER_STRING_SIZE));
    free(tmp);
    return rope;
}

void print_node(Node *node){
    if (node->substring != NULL) {
        printf("%s", node->substring->first_char);
    } else {
        print_node(node->leftNeighbour);
        print_node(node->rightNeighbour);
    }
}

void print_rope(Rope rope) {
    print_node(rope.root);
    printf("\n");
}


//Insert a node in a rope at a given index
void rope_insert_at(Rope *rope, String *string, unsigned int* index) {
    Node *parentNode = NULL;
    bool isLeft = false;
    Node *node = get_node_at_index(rope->root, index, &parentNode, &isLeft);

    if (node != NULL) {
        int newStringLength = node->substring->size + string->size;
        char *newString = malloc((newStringLength + 1) * sizeof(char));

        if (newString != NULL) {
            strncpy(newString, node->substring->first_char, *index);
            newString[*index] = '\0';
            strcat(newString, string->first_char);
            strcat(newString, node->substring->first_char + *index);
//            free_string(node->substring->first_char, node->substring->size);
            free(node->substring);
            node->substring = NULL;
            Node* nodeAdd = init_node(init_string(newString), &rope->MAX_INNER_STRING_SIZE);
            if (isLeft) {
                parentNode->leftNeighbour = nodeAdd;
            } else {
                parentNode->rightNeighbour = nodeAdd;
            }
        }
        free(newString);
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

void rope_delete(Rope *rope) {
    if (rope == NULL) {
        return; // Rien à faire si rope est NULL
    }
    // Appeler une fonction récursive pour libérer les nœuds
    recursive_node_free(rope->root);
    free(rope); // Libérer la structure Rope elle-même
}

void recursive_node_free(Node *node) {
    if (node == NULL) {
        return;
    }

    recursive_node_free(node->leftNeighbour); // Libérer les nœuds de gauche
    recursive_node_free(node->rightNeighbour); // Libérer les nœuds de droite

    if (node->substring != NULL) {
//        free_string(node->substring->first_char, node->substring->size); // Libérer la chaîne de caractères
        free(node->substring); // Libérer la structure String
    }

    free(node); // Libérer le nœud actuel
}







