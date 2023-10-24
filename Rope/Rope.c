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
Rope init_rope(char *string, int substring_size) {
    char *string2 = strdup(string);
    Rope *rope = malloc(sizeof(Rope));
    rope->MAX_INNER_STRING_SIZE = (unsigned int) substring_size;
    rope->root = *init_node(string2, &(rope->MAX_INNER_STRING_SIZE));
    return *rope;
}

//Insert a node in a rope at a given index
void concatenate(Rope *rope, char *string, int index) {
    int substring_start_index = 0;
    Node previousNode;
    Node *node = get_node_at_index(&rope->root, index);

    if (node != NULL) {
        int newStringLength = strlen(node->substring) + strlen(string); //Cassé car node est pas le bon c'est qui a 6
        char *newString = malloc((newStringLength + 1) * sizeof(char));

        if (newString != NULL) {
            strcpy(newString, node->substring);
            strcat(newString, string);

            // Réassigner la chaîne dans le nœud
            free(node->substring);
            node->substring = NULL; //Au lieu de remplacer faut créer un nouveau rope
            Rope newRope = init_rope(newString, 3); //atentions
            previousNode.rightNeighbour = &newRope.root; //atentions
        }
    }
}


// a gauche je retourne left et a droite je retourne right et j'enleve a l'index le label

Node *get_node_at_index(Node *node, int index) {
    if (node == NULL){return NULL;}
    if (node->substring != NULL) {
        return node;
    }
    if (index <= node->label) {
        return get_node_at_index(node->leftNeighbour, index );
    } else {
        return get_node_at_index(node->rightNeighbour, index-node->label);
    }
}




