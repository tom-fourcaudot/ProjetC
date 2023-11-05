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
//        size_t len = rope_len(rope);  // TO DO
        size_t len = strlen(base);
        size_t pos = rand() % len;
//        int start = dfs(rope->root);
//        printf("start: %d\n", start);
        rope_insert_at(rope, init_string(base), (unsigned int *) &pos);
//        int end = dfs(rope->root);
//        printf("end: %d\n", end);
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

int main()
{
    srand(time(NULL));

    const size_t nb_chars = 10000;
    const size_t nb_insertions = 1000;
    const size_t nb_repetitions = 50;
    const int substring_size = 3;

    char *base = (char *)malloc(sizeof(char) * (1 + nb_chars));
    for (int i = 0; i < nb_chars; ++i)
    {
        base[i] = 'a' + (i % 25);
    }
    base[nb_chars] = '\0';

    printf("METHOD;CONSTRUCTION;INSERTION;DESTRUCTION;NOMBRE_INITIALISaTION;NOMBRE_INSERTION;NOMBRE_DESTRUCTION\n");
    for (int r = 0; r < nb_repetitions; ++r)
    {
        clock_t start_create = clock();
        float nombre_initialisation = strlen(base);
        float nombre_insertion = nb_insertions * strlen(base);
        float nombre_destruction = nombre_initialisation + nombre_insertion;
        Rope *rope = init_rope(base, substring_size); // TO DO
        assert(rope != NULL);
        clock_t start_insert = clock();
        bench_rope(rope, base, nb_insertions);
        clock_t start_delete = clock();
        rope_delete(rope);
        clock_t stop_delete = clock();

        float create_time = (float)(start_insert - start_create) / CLOCKS_PER_SEC;
        float insert_time = (float)(start_delete - start_insert) / CLOCKS_PER_SEC;
        float delete_time = (float)(stop_delete - start_delete) / CLOCKS_PER_SEC;

        printf("ROPE;%f;%f;%f;%f;%f;%f\n", create_time, insert_time, delete_time, nombre_initialisation, nombre_insertion, nombre_destruction);
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


int main_tmp(){
    unsigned int* sub_size = malloc(sizeof (unsigned int));
    int size = 3;
    int size2 = 10000;
    char *ma_chaine = (char *)malloc(sizeof(char) * (size2 + 1)); // +1 pour le caractère nul de fin de chaîne

    for (int i = 0; i < size2; ++i) {
        ma_chaine[i] = 'a' + (i % 25);
    }
    ma_chaine[size2] = '\0';
    printf("ma_chaine: %zu\n", strlen(ma_chaine));
    Rope* rope = init_rope(ma_chaine, size);
    int nbr = dfs(rope->root);
    printf("nbr: %d\n", nbr);
    int pos = 5;
    String* stringToInsert = init_string(ma_chaine);
    float time1= clock();
    rope_insert_at(rope, stringToInsert, (unsigned int *) &pos);
    float time2= clock();
    printf("time: %f\n", (time2-time1)/CLOCKS_PER_SEC);
    int nbr2 = dfs(rope->root);
    printf("nbr2: %d\n", nbr2);
    rope_delete(rope);
//    int nbr3 = dfs(rope->root);
//    printf("nbr3: %d\n", nbr3); comme rope delete sa crache le dfs
    return 0;
}