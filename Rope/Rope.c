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

// Print the string in a rope
void print_rope(Rope *rope) {
    if (rope == NULL) {
        return;
    }
    print_node(rope->root);
    printf("\n");
}

// Return the number of char under a node
int rope_len(Node* node) {
    if(node == NULL) {return 0;}
    if (node->substring != NULL) {
        return (int) node->substring->size;
    } else {
        return node->label + rope_len(node->rightNeighbour);
    }
}

// Create a new Rope from 2 nodes
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

// Split the rope at the index
// Return the right part of the rope
// The input rope will be modified to become the left part of the rope
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
    rope->root->label = rope_len(rope->root->leftNeighbour);
    return right_rope;
}

// Insert a string in the rope
void insert_at(Rope* rope, char* string, int index) {
    Rope* to_insert = init_rope(string, (int)rope->MAX_INNER_STRING_SIZE);
    Rope* S3 = split_rope(rope, index);
    rope->root = concatenate_from_node(rope->root, to_insert->root);
    rope->root = concatenate_from_node(rope->root, S3->root);
    free(S3);
    free(to_insert);
}


// Free the rope and its datas
void free_rope (Rope *rope) {
    if (rope == NULL) {return;}
    free_node(rope->root);
    free(rope);
}