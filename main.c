#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include "Rope/Rope.h"



// gcc bench.c -O3  -Wall -Wextra &&  ./a.out | tee bench.csv

void bench_rope(Rope *rope, char *base, size_t nb_insertions)
{

    for (int i = 0; i < nb_insertions; ++i)
    {
        size_t len = rope_len(rope->root);
//        size_t len = strlen(base);
        size_t pos = rand() % len;
        int start = dfs(rope->root);
        // printf("start: %d\n", start);
        insert_at(rope, base, (int)pos);
        int end = dfs(rope->root);
        // printf("end: %d\n", end);
    }
}

void bench_string(char **s, char *base, size_t nb_insertions)
{
    size_t base_len = strlen(base);

    for (int i = 0; i < nb_insertions; ++i)
    {
        // chose location to insert
        size_t old_len = strlen(*s);
        size_t pos = rand() % old_len;

        // start insertion
        size_t left_len = pos;
        // size_t right_len = old_len-pos;
        size_t new_len = old_len + base_len;

        // s is at the right lenght
        *s = realloc(*s, new_len + 1);

        // move right part to the right
        for (size_t i = old_len - 1; i >= left_len; --i)
        {
            (*s)[new_len + i - old_len] = (*s)[i];
        }
        // inject the base
        for (size_t i = 0; i < base_len; ++i)
        {
            (*s)[left_len + i] = base[i];
        }
        // ensure this is a valid string
        (*s)[new_len] = '\0';
    }
}

int main_tmp()
{
    srand(time(NULL));

    const size_t nb_chars = 10000;
    const size_t nb_insertions = 1000;
    const size_t nb_repetitions = 50;
    const int substring_size = 100;

    char *base = (char *)malloc(sizeof(char) * (1 + nb_chars));
    for (int i = 0; i < nb_chars; ++i)
    {
        base[i] = 'a' + (i % 25);
    }
    base[nb_chars] = '\0';

    printf("METHOD;CONSTRUCTION;INSERTION;DESTRUCTION\n");
    for (int r = 0; r < nb_repetitions; ++r)
    {
        printf("_____Repetition %d_____\n", r);
        clock_t start_create = clock();
        Rope *rope = init_rope(base, substring_size); // TO DO
        assert(rope != NULL);
        clock_t start_insert = clock();
        bench_rope(rope, base, nb_insertions);
        clock_t start_delete = clock();
        free_rope(rope);
        clock_t stop_delete = clock();

        float create_time = (float)(start_insert - start_create) / CLOCKS_PER_SEC;
        float insert_time = (float)(start_delete - start_insert) / CLOCKS_PER_SEC;
        float delete_time = (float)(stop_delete - start_delete) / CLOCKS_PER_SEC;

        printf("ROPE;%f;%f;%f\n", create_time, insert_time, delete_time);
    }

    for (int r = 0; r < nb_repetitions; ++r)
    {
        clock_t start_create = clock();
        char *s = (char *)malloc(sizeof(char) * (strlen(base) + 1));
        strcpy(s, base);

        clock_t start_insert = clock();
        bench_string(&s, base, nb_insertions);

        clock_t start_delete = clock();
        free(s);
        clock_t stop_delete = clock();

        float create_time = (float)(start_insert - start_create) / CLOCKS_PER_SEC;
        float insert_time = (float)(start_delete - start_insert) / CLOCKS_PER_SEC;
        float delete_time = (float)(stop_delete - start_delete) / CLOCKS_PER_SEC;

        printf("STR;%f;%f;%f\n", create_time, insert_time, delete_time);
    }

    free(base);

    return 0;
}


int main(){
    main_tmp();
    return 0;
}