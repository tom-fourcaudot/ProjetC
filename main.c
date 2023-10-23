#include <stdio.h>
#include <stdlib.h>
#include "Rope/Node.h"

int main() {
    unsigned int* sub_size = malloc(sizeof (unsigned int));
    *sub_size = 3;
    char* string = malloc(26 * sizeof (char));
    string = "abcdefghijklmnopqrstuvwxyz";
    Node* node = init_node(string, sub_size);
    printf("%d", node->leftNeighbour->label);
    printf("%s", node->leftNeighbour->substring);
    free(sub_size);
    return 0;
}
