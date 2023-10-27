#include "Rope/Rope.h"

int main() {
    Rope rope = init_rope("Bonjour je suis une string tout a fais normal, je suis peut etre juste un peu longue pour etre initialiser dans un tableau, donc je choisis de me mettre dans une rope !!!", 3);
    print_rope(rope);
    return 0;
}

