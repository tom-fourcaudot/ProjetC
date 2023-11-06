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
Rope * init_rope(char* string, int substring_size){
    char* tmp = strdup(string);
    String *string_struct = init_string(tmp);
    Rope* rope = malloc(sizeof (Rope));
    rope->MAX_INNER_STRING_SIZE = (unsigned int)substring_size;
    rope->root = init_node(string_struct, &(rope->MAX_INNER_STRING_SIZE));
    free(tmp);
    return rope;
}

void print_rope(Rope *rope) {
    if (rope == NULL) {
        return;
    }
    print_node(rope->root);
    printf("\n");
}

int rope_len(Node* node) {
    if(node == NULL) {return 0;}
    if (node->substring != NULL) {
        return (int) node->substring->size;
    } else {
        return rope_len(node->leftNeighbour) + rope_len(node->rightNeighbour);
    }
}



Node* concatenate_from_node(Node* left_node, Node* right_node) {
    if(left_node == NULL) {return NULL;}
    if(right_node == NULL) {return left_node;}
    Node* root = malloc(sizeof (Node));
    root->label = rope_len(left_node);
    left_node->parent = root;
    right_node->parent = root;
    root->parent = NULL;
    root->leftNeighbour = left_node;
    root->rightNeighbour = right_node;
    root->substring = NULL;
    return root;
}

Rope* concatenate(Rope* left_rope, Rope* right_rope) {
    Rope* result = malloc(sizeof (Rope));
    result->root = concatenate_from_node(left_rope->root, right_rope->root);
    free(left_rope);
    free(right_rope);
    return result;
}

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

Rope* split_rope(Rope* rope, int index) {
    if (index < 0) {return NULL;}
    int* tmp_index = malloc(sizeof (int));
    *tmp_index = index;
    Node* to_split = find_node_at_index(rope->root, tmp_index);
    if (*tmp_index > to_split->substring->size) {return NULL;}
    if (*tmp_index != to_split->substring->size) {
        split_node(*tmp_index, to_split);
        to_split = to_split->leftNeighbour;
    }
    free(tmp_index);
    Rope* right_rope = malloc(sizeof (Rope));
    right_rope->MAX_INNER_STRING_SIZE = rope->MAX_INNER_STRING_SIZE;
    right_rope->root = NULL;
    while(to_split != rope->root) {
        if (to_split != to_split->parent->rightNeighbour) {
            if (to_split->parent->rightNeighbour != NULL) {
                if (right_rope->root == NULL) {
                    right_rope->root = to_split->parent->rightNeighbour;
                } else {
                    right_rope->root = concatenate_from_node(right_rope->root, to_split->parent->rightNeighbour);
                }
                to_split->parent->rightNeighbour = NULL;

            }
        }
        // update labels
        if (to_split->leftNeighbour != NULL){to_split->label = rope_len(to_split->leftNeighbour);}
        to_split = to_split->parent;
    }
    // handle left or right split
    if (index <= rope->root->label) {
        right_rope->root = concatenate_from_node(right_rope->root, rope->root->rightNeighbour);
        rope->root->rightNeighbour = NULL;
    }
    rope->root->label = rope_len(rope->root);
    return right_rope;
}

void insert_at(Rope* rope, char* string, int index) {
    Rope* to_insert = init_rope(string, (int)rope->MAX_INNER_STRING_SIZE);
    Rope* S3 = split_rope(rope, index);
    rope->root = concatenate_from_node(rope->root, to_insert->root);
    rope->root = concatenate_from_node(rope->root, S3->root);
    free(S3);
    free(to_insert);
}

int dfs(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return dfs(node->leftNeighbour) + dfs(node->rightNeighbour) + 1;
}

void free_rope (Rope *rope) {
    if (rope == NULL) {return;}
    free_node(rope->root);
    free(rope);
}