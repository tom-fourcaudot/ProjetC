#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include "Rope/Rope.h"



// gcc bench.c -O3  -Wall -Wextra &&  ./a.out | tee bench.csv

void str_insert_at(char **s, char *base, int index){
    size_t base_len = strlen(base);

    // chose location to insert
    size_t old_len = strlen(*s);

    // start insertion
    size_t left_len = index;
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

void test_insert_connu(int index_insert){
    printf("INSERTION_CONNU\n");

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

    printf("METHOD;INSERTION;INDEX\n");
    for (int r = 0; r < nb_repetitions; ++r)
    {
        Rope *rope = init_rope(base, substring_size); // TO DO
        assert(rope != NULL);
        clock_t start_insert = clock();
        insert_at(rope, base, (int)index_insert);
        clock_t start_delete = clock();
        free_rope(rope);

        float insert_time = (float)(start_delete - start_insert) / CLOCKS_PER_SEC;

        printf("ROPE;%f;%d\n", insert_time, index_insert);
    }

    for (int r = 0; r < nb_repetitions; ++r)
    {
        char *s = (char *)malloc(sizeof(char) * (strlen(base) + 1));
        strcpy(s, base);
        clock_t start_insert = clock();
        str_insert_at(&s, base, index_insert);
        clock_t start_delete = clock();
        free(s);
        float insert_time = (float)(start_delete - start_insert) / CLOCKS_PER_SEC;
        printf("STR;%f;%d\n", insert_time, index_insert);
    }
    free(base);
}

void test_construction(){
    printf("CONSTRUCTION\n");

    srand(time(NULL));
    const size_t nb_insertions = 1000;
    const size_t nb_repetitions = 50;
    const int substring_size = 100;


    printf("METHOD;CONSTRUCTION;NOMBRE_DE_CARACTERE\n");
    for (int r = 0; r < nb_repetitions; ++r)
    {
        size_t nb_chars = 10000 * (r+1);

        char *base = (char *)malloc(sizeof(char) * (1 + nb_chars));
        for (int i = 0; i < nb_chars; ++i)
        {
            base[i] = 'a' + (i % 25);
        }
        base[nb_chars] = '\0';

        clock_t start_insert = clock();
        Rope *rope = init_rope(base, substring_size); // TO DO
        clock_t start_delete = clock();
        free_rope(rope);
        float construction_time = (float)(start_delete - start_insert) / CLOCKS_PER_SEC;
        int size_caractere = strlen(base);
        printf("ROPE;%f;%d\n", construction_time, size_caractere);
        free(base);
    }

    for (int r = 0; r < nb_repetitions; ++r)
    {
        size_t nb_chars = 10000 * (r+1);

        char *base = (char *)malloc(sizeof(char) * (1 + nb_chars));
        for (int i = 0; i < nb_chars; ++i)
        {
            base[i] = 'a' + (i % 25);
        }
        base[nb_chars] = '\0';

        char *s = (char *)malloc(sizeof(char) * (strlen(base) + 1));
        clock_t start_insert = clock();
        strcpy(s, base);
        clock_t start_delete = clock();
        free(s);
        int size_caractere = strlen(base);
        float construction_time = (float)(start_delete - start_insert) / CLOCKS_PER_SEC;
        printf("STR;%f;%d\n", construction_time, size_caractere);
        free(base);
    }
}

void insert_repetition_meme_index(int repetition){
    printf("INSERTION_REPETITION_MEME_INDEX\n");

    const int index_insert = 100;

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

    printf("METHOD;INSERTION;NOMBRE_DE_REPETITION\n");
    for (int r = 0; r < nb_repetitions; ++r)
    {
        Rope *rope = init_rope(base, substring_size); // TO DO
        assert(rope != NULL);
        clock_t start_insert = clock();
        for (int i = 0; i < repetition; ++i){
            insert_at(rope, base, (int)index_insert);
        }
        clock_t start_delete = clock();
        free_rope(rope);

        float insert_time = (float)(start_delete - start_insert) / CLOCKS_PER_SEC;

        printf("ROPE;%f;%d\n", insert_time, repetition);
    }

    for (int r = 0; r < nb_repetitions; ++r)
    {
        char *s = (char *)malloc(sizeof(char) * (strlen(base) + 1));
        strcpy(s, base);
        clock_t start_insert = clock();
        for (int i = 0; i < repetition; ++i){
            str_insert_at(&s, base, index_insert);
        }
        clock_t start_delete = clock();
        free(s);
        float insert_time = (float)(start_delete - start_insert) / CLOCKS_PER_SEC;
        printf("STR;%f;%d\n", insert_time, repetition);
    }
    free(base);
}

void insert_repetition_index_different(int repetition){
    printf("INSERTION_REPETITION_INDEX_DIFFERENT\n");

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

    printf("METHOD;INSERTION;NOMBRE_DE_REPETITION\n");
    for (int r = 0; r < nb_repetitions; ++r)
    {
        int index_insert = rand() % nb_chars;
        Rope *rope = init_rope(base, substring_size); // TO DO
        assert(rope != NULL);
        clock_t start_insert = clock();
        for (int i = 0; i < repetition; ++i){
            insert_at(rope, base, (int)index_insert);
        }
        clock_t start_delete = clock();
        free_rope(rope);

        float insert_time = (float)(start_delete - start_insert) / CLOCKS_PER_SEC;

        printf("ROPE;%f;%d\n", insert_time, repetition);
    }

    for (int r = 0; r < nb_repetitions; ++r)
    {
        int index_insert = rand() % nb_chars;
        char *s = (char *)malloc(sizeof(char) * (strlen(base) + 1));
        strcpy(s, base);
        clock_t start_insert = clock();
        for (int i = 0; i < repetition; ++i){
            str_insert_at(&s, base, index_insert);
        }
        clock_t start_delete = clock();
        free(s);
        float insert_time = (float)(start_delete - start_insert) / CLOCKS_PER_SEC;
        printf("STR;%f;%d\n", insert_time, repetition);
    }
    free(base);
}

void insertion_meme_index_taille_insertion_differente(){
    printf("INSERTION_TAILLE_INSERTION_DIFFERENT\n");

    srand(time(NULL));
    const size_t nb_chars = 10000;
    const size_t nb_insertions = 1000;
    const size_t nb_repetitions = 50;
    const int substring_size = 100;
    const int index_insert = 100;

    char *base = (char *)malloc(sizeof(char) * (1 + nb_chars));
    for (int i = 0; i < nb_chars; ++i)
    {
        base[i] = 'a' + (i % 25);
    }
    base[nb_chars] = '\0';

    printf("METHOD;INSERTION;TAILLE_DE_L_INSERTION\n");
    for (int r = 0; r < nb_repetitions; ++r)
    {
        int nb_chars_2 = 10000 * (r+1);

        char *base2 = (char *)malloc(sizeof(char) * (1 + nb_chars_2));
        for (int i = 0; i < nb_chars_2; ++i)
        {
            base2[i] = 'a' + (i % 25);
        }
        base2[nb_chars] = '\0';

        Rope *rope = init_rope(base, substring_size); // TO DO
        assert(rope != NULL);
        clock_t start_insert = clock();
        insert_at(rope, base2, (int)index_insert);
        clock_t start_delete = clock();
        free_rope(rope);

        float insert_time = (float)(start_delete - start_insert) / CLOCKS_PER_SEC;

        printf("ROPE;%f;%d\n", insert_time, nb_chars_2);
        free(base2);
    }

    for (int r = 0; r < nb_repetitions; ++r)
    {
        int nb_chars_2 = 10000 * (r+1);

        char *base2 = (char *)malloc(sizeof(char) * (1 + nb_chars_2));
        for (int i = 0; i < nb_chars_2; ++i)
        {
            base2[i] = 'a' + (i % 25);
        }
        base2[nb_chars] = '\0';

        char *s = (char *)malloc(sizeof(char) * (strlen(base) + 1));
        strcpy(s, base);
        clock_t start_insert = clock();
        str_insert_at(&s, base2, index_insert);
        clock_t start_delete = clock();
        free(s);
        float insert_time = (float)(start_delete - start_insert) / CLOCKS_PER_SEC;
        printf("STR;%f;%d\n", insert_time, nb_chars_2);
        free(base2);
    }
    free(base);
}

void test_insert_taille_structure_differente(){
    printf("INSERTION_TAILLE_STRUCTURE_DIFFERENT\n");

    srand(time(NULL));
    const size_t nb_chars = 10000;
    const size_t nb_insertions = 1000;
    const size_t nb_repetitions = 50;
    const int substring_size = 100;
    const int index_insert = 100;

    char *base = (char *)malloc(sizeof(char) * (1 + nb_chars));
    for (int i = 0; i < nb_chars; ++i)
    {
        base[i] = 'a' + (i % 25);
    }
    base[nb_chars] = '\0';

    printf("METHOD;INSERTION;TAILLE_DE_LA_STRUCTURE\n");
    for (int r = 0; r < nb_repetitions; ++r)
    {
        int nb_chars_2 = 10000 * (r+1);

        char *base2 = (char *)malloc(sizeof(char) * (1 + nb_chars_2));
        for (int i = 0; i < nb_chars_2; ++i)
        {
            base2[i] = 'a' + (i % 25);
        }
        base2[nb_chars] = '\0';

        Rope *rope = init_rope(base2, substring_size); // TO DO
        assert(rope != NULL);
        clock_t start_insert = clock();
        insert_at(rope, base, (int)index_insert);
        clock_t start_delete = clock();
        free_rope(rope);

        float insert_time = (float)(start_delete - start_insert) / CLOCKS_PER_SEC;

        printf("ROPE;%f;%d\n", insert_time, nb_chars_2);
        free(base2);
    }

    for (int r = 0; r < nb_repetitions; ++r)
    {
        int nb_chars_2 = 10000 * (r+1);

        char *base2 = (char *)malloc(sizeof(char) * (1 + nb_chars_2));
        for (int i = 0; i < nb_chars_2; ++i)
        {
            base2[i] = 'a' + (i % 25);
        }
        base2[nb_chars] = '\0';

        char *s = (char *)malloc(sizeof(char) * (strlen(base2) + 1));
        strcpy(s, base2);
        clock_t start_insert = clock();
        str_insert_at(&s, base, index_insert);
        clock_t start_delete = clock();
        free(s);
        float insert_time = (float)(start_delete - start_insert) / CLOCKS_PER_SEC;
        printf("STR;%f;%d\n", insert_time, nb_chars_2);
        free(base2);
    }
    free(base);
}

void test_delete(){
    printf("DESTRUCTION\n");

    srand(time(NULL));
    const size_t nb_insertions = 1000;
    const size_t nb_repetitions = 50;
    const int substring_size = 100;

    printf("METHOD;CONSTRUCTION;NOMBRE_DE_CARACTERE\n");
    for (int r = 0; r < nb_repetitions; ++r)
    {
        size_t nb_chars = 10000 * (r+1);

        char *base = (char *)malloc(sizeof(char) * (1 + nb_chars));
        for (int i = 0; i < nb_chars; ++i)
        {
            base[i] = 'a' + (i % 25);
        }
        base[nb_chars] = '\0';

        Rope *rope = init_rope(base, substring_size); // TO DO

        clock_t start_destruction= clock();
        free_rope(rope);
        clock_t end_destruction = clock();
        float destruction_time = (float)(end_destruction - start_destruction) / CLOCKS_PER_SEC;
        int size_caractere = strlen(base);
        printf("ROPE;%f;%d\n", destruction_time, size_caractere);
        free(base);
    }

    for (int r = 0; r < nb_repetitions; ++r)
    {
        size_t nb_chars = 10000 * (r+1);

        char *base = (char *)malloc(sizeof(char) * (1 + nb_chars));
        for (int i = 0; i < nb_chars; ++i)
        {
            base[i] = 'a' + (i % 25);
        }
        base[nb_chars] = '\0';

        char *s = (char *)malloc(sizeof(char) * (strlen(base) + 1));
        strcpy(s, base);
        clock_t start_insert = clock();
        free(s);
        clock_t start_delete = clock();
        int size_caractere = strlen(base);
        float construction_time = (float)(start_delete - start_insert) / CLOCKS_PER_SEC;
        printf("STR;%f;%d\n", construction_time, size_caractere);
        free(base);
    }
}


int main(){
    //CONSTRUCTION
    test_construction();

    //INSERT
    //test insert index connu
    test_insert_connu(1);
    test_insert_connu(100);
    test_insert_connu(1000);

    //test insert repetition meme index
    insert_repetition_meme_index(50);
    insert_repetition_meme_index(500);
    insert_repetition_meme_index(5000);

    //test insert repetition index different
    insert_repetition_index_different(50);
    insert_repetition_index_different(500);
    insert_repetition_index_different(5000);

    // test insert au meme endroit avec des tailles d'insertion differentes
    insertion_meme_index_taille_insertion_differente();

    // test insert de la meme taille avec un taille de structure differente
    test_insert_taille_structure_differente();

    //DELETE
    test_delete();
    return 0;
}