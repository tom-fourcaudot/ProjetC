//
// Created by toum on 10/16/23.
//
#include "Node.h"
#include "String.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Create a node which contain a string
Node * init_node(String* string, const unsigned int* substring_size) {
    Node* node = malloc(sizeof (Node));
    node->parent = NULL;
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
        node->rightNeighbour->parent = node;
        node->label = string->size;
        node->leftNeighbour = init_node(string, substring_size);
        node->leftNeighbour->parent = node;
        node->substring = NULL;
    }
    return node;
}

// Print the string contain in the node
void print_node(Node *node){
    if(node == NULL){ return;}
    if (node->substring != NULL) {
        printf("%s", node->substring->first_char);
    } else {
        print_node(node->leftNeighbour);
        print_node(node->rightNeighbour);
    }
}

// Count the number of node under a node
int dfs(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return dfs(node->leftNeighbour) + dfs(node->rightNeighbour) + 1;
}

// Find the node at the index of the string
Node* find_node_at_index(Node* node, int* index) {
    if (node == NULL){
        return NULL;}
    if (*index < 0){
        return NULL;}
    if (*index > node->label) {
        *index -= (int)node->label;
        return find_node_at_index(node->rightNeighbour, index);
    } else {
        if (node->leftNeighbour != NULL) {
            return find_node_at_index(node->leftNeighbour, index);
        } else {
            return node;
        }
    }
}

// Split a node at an index, to simplify the insertion
void split_node(int tmp_index, Node *to_split) {
    // We split the String
    int right_string_len = (int)to_split->substring->size - tmp_index;
    char* left_string = malloc((tmp_index + 1) * sizeof (char));
    char* right_string = malloc((right_string_len + 1) * sizeof (char));
    memcpy(left_string, to_split->substring->first_char, tmp_index);
    *(left_string + tmp_index) = '\0';
    memcpy(right_string, to_split->substring->first_char + tmp_index, right_string_len);
    *(right_string + right_string_len) = '\0';
    free_string(to_split->substring);
    to_split->substring = NULL;
    // We create 2 child nodes
    to_split->leftNeighbour = malloc(sizeof (Node));
    to_split->leftNeighbour->leftNeighbour = NULL;
    to_split->leftNeighbour->rightNeighbour = NULL;
    to_split->leftNeighbour->parent = to_split;
    to_split->leftNeighbour->substring = init_string(left_string);
    to_split->leftNeighbour->label = to_split->leftNeighbour->substring->size;
    to_split->rightNeighbour = malloc(sizeof (Node));
    to_split->rightNeighbour->leftNeighbour = NULL;
    to_split->rightNeighbour->rightNeighbour = NULL;
    to_split->rightNeighbour->parent = to_split;
    to_split->rightNeighbour->substring = init_string(right_string);
    to_split->rightNeighbour->label = to_split->rightNeighbour->substring->size;
    to_split->label = to_split->leftNeighbour->label;
}

// free the node
void free_node(Node *node){
    if (node == NULL){return;}
    free_node(node->leftNeighbour);
    free_node(node->rightNeighbour);
    free_string(node->substring);
    free(node);
}