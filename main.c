#include <stdio.h>
#include <stdlib.h>
#include "Rope/Node.h"
#include "Rope/Rope.h"

int main() {
    unsigned int* sub_size = malloc(sizeof (unsigned int));
    Rope rope = init_rope("abcdefghijklmnopqrstuvwxyz", 3);
    int index = 5;
    concatenate(&rope, "123456789", &index);
    return 0;
}

