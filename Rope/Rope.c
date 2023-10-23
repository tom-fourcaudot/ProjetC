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
Rope init_rope(char* string, int substring_size){
    char* string2 = strdup(string);
    Rope* rope = malloc(sizeof (Rope));
    rope->MAX_INNER_STRING_SIZE = (unsigned int)substring_size;
    rope->root = *init_node(string2, &(rope->MAX_INNER_STRING_SIZE));
    return *rope;
}

//Insert a node in a rope at a given index
void concatenate(Rope* rope, char* string, int index){
    int substring_start_index = 0;
    Node previousNode;
    Node *node = get_node_at_index(&rope->root, index, &substring_start_index, &previousNode);

    if (node != NULL) {
        int newStringLength = strlen(node->substring) + strlen(string);
        char* newString = malloc((newStringLength + 1) * sizeof(char));

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

Node* get_node_at_index(Node* node, int index, int* substring_start_index, Node* previousNode) {
    if (node == NULL) return NULL;
    if (index < 0) return NULL;

    int leftSize = node->leftNeighbour ? strlen(node->leftNeighbour->substring) : 0;

    if (index < leftSize) {
        return get_node_at_index(node->leftNeighbour, index, substring_start_index, previousNode);
    } else if (index < leftSize + strlen(node->substring)) {
        *substring_start_index = index - leftSize; // Indice relatif au début de la sous-chaîne

        // Passer le nœud précédent
        if (previousNode != NULL) {
            *previousNode = *node;
        }

        return node;
    } else {
        return get_node_at_index(node->rightNeighbour, index - leftSize - strlen(node->substring), substring_start_index, node);
    }
}




