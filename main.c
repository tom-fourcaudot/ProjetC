#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include "Rope/Rope.h"



// gcc bench.c -O3  -Wall -Wextra &&  ./a.out | tee bench.csv


int main()
{
    srand(time(NULL));

    const size_t nb_insertions = 1000;
    const size_t nb_repetitions = 50;
    const int substring_size = 3;

    printf("METHOD;CONSTRUCTION;NOMBRE_DE_CARACTERE\n");
    for (int r = 0; r < nb_repetitions; ++r)
    {
        size_t nb_chars = 10000 * (r + 1);

        char *base = (char *)malloc(sizeof(char) * (1 + nb_chars));
        for (int i = 0; i < nb_chars; ++i)
        {
            base[i] = 'a' + (i % 25);
        }
        base[nb_chars] = '\0';

        clock_t start_create = clock();
        Rope *rope = init_rope(base, substring_size); // TO DO
        clock_t start_insert = clock();
        float create_time = (float)(start_insert - start_create) / CLOCKS_PER_SEC;

        float size = strlen(base);

        printf("ROPE;%f;%f\n", create_time, size);
    }

    for (int r = 0; r < nb_repetitions; ++r)
    {
        size_t nb_chars = 10000 * (r + 1);

        char *base = (char *)malloc(sizeof(char) * (1 + nb_chars));
        for (int i = 0; i < nb_chars; ++i)
        {
            base[i] = 'a' + (i % 25);
        }
        base[nb_chars] = '\0';

        clock_t start_create = clock();
        char *s = (char *)malloc(sizeof(char) * (strlen(base) + 1));
        strcpy(s, base);

        clock_t start_insert = clock();

        float create_time = (float)(start_insert - start_create) / CLOCKS_PER_SEC;

        float size = strlen(s);

        printf("STR;%f;%f\n", create_time, size);
    }
    return 0;
}