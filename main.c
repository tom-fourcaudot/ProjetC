#include <stdio.h>
#include <stdlib.h>
#include "Rope/Node.h"
#include "Rope/Rope.h"

int main() {
    Rope rope = init_rope("123456789abcdefghijkl", 3);
    print_rope(rope);
    return 0;
}

