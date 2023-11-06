#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include "Rope/Rope.h"



// gcc bench.c -O3  -Wall -Wextra &&  ./a.out | tee bench.csv

void bench_string_index(char **s, char *base, size_t pos)
{
    size_t base_len = strlen(base);

    size_t old_len = strlen(*s);

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

int main_TMP2()
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

    printf("METHOD;CONSTRUCTION;INSERTION;NOMBRE_DE_CARACTERE\n");
    for (int r = 0; r < nb_repetitions; ++r)
    {
        Rope *rope = init_rope(base, substring_size); // TO DO
        assert(rope != NULL);
        clock_t start_insert = clock();
        bench_rope(rope, base, nb_insertions);
        clock_t start_delete = clock();


        float insert_time = (float)(start_delete - start_insert) / CLOCKS_PER_SEC;
        float size = strlen(base);

        printf("ROPE;%f;%f\n", insert_time, size);
    }

    for (int r = 0; r < nb_repetitions; ++r)
    {
        char *s = (char *)malloc(sizeof(char) * (strlen(base) + 1));
        strcpy(s, base);

        clock_t start_insert = clock();
        bench_string(&s, base, nb_insertions);
        clock_t start_delete = clock();


        float insert_time = (float)(start_delete - start_insert) / CLOCKS_PER_SEC;
        float size = strlen(base);

        printf("STR;%f;%f\n", insert_time, size);
    }

    free(base);
    return 0;
}


//index precis
int main_tr(){
    srand(time(NULL));

    const size_t nb_chars = 10000;
    const size_t nb_insertions = 1000;
    const size_t nb_repetitions = 50;
    const int substring_size = 3;
    const int index = 100000;

    char *base = (char *)malloc(sizeof(char) * (1 + nb_chars));
    for (int i = 0; i < nb_chars; ++i)
    {
        base[i] = 'a' + (i % 25);
    }
    base[nb_chars] = '\0';

    printf("METHOD;INSERTION;NOMBRE_DE_CARACTERE;INDEX\n");
    for (int r = 0; r < nb_repetitions; ++r)
    {
        Rope *rope = init_rope(base, substring_size); // TO DO
        assert(rope != NULL);
        clock_t start_insert = clock();
        rope_insert_at(rope, init_string(base), (unsigned int *) &index);
        clock_t start_delete = clock();


        float insert_time = (float)(start_delete - start_insert) / CLOCKS_PER_SEC;
        float size = strlen(base);

        printf("ROPE;%f;%f;%d\n", insert_time, size,index);
    }
    //str
    for (int r = 0; r < nb_repetitions; ++r)
    {
        char *s = (char *)malloc(sizeof(char) * (strlen(base) + 1));
        strcpy(s, base);

        clock_t start_insert = clock();


        bench_string_index(&s, base, index);

        clock_t start_delete = clock();


        float insert_time = (float)(start_delete - start_insert) / CLOCKS_PER_SEC;
        float size = strlen(base);

        printf("STR;%f;%f,%d\n", insert_time, size, index);
    }
}


//répétition au meme index
int main_dz(){
    srand(time(NULL));

    const size_t nb_chars = 10000;
    const size_t nb_insertions = 1000;
    const size_t nb_repetitions = 5000;
    const int substring_size = 3;
    const int index = 100000;

    char *base = (char *)malloc(sizeof(char) * (1 + nb_chars));
    for (int i = 0; i < nb_chars; ++i)
    {
        base[i] = 'a' + (i % 25);
    }
    base[nb_chars] = '\0';

    printf("METHOD;INSERTION;REPETITION\n");
    for (int r = 0; r < 50; ++r)
    {
        Rope *rope = init_rope(base, substring_size); // TO DO
        assert(rope != NULL);
        clock_t start_insert = clock();
        for (int i = 0; i < nb_insertions; ++i){
            rope_insert_at(rope, init_string(base), (unsigned int *) &index);
        }
        clock_t start_delete = clock();
        float insert_time = (float)(start_delete - start_insert) / CLOCKS_PER_SEC;
        printf("ROPE;%f;%zu\n", insert_time, nb_repetitions);
        rope_delete(rope);
    }
    //str
    for (int r = 0; r < 50; ++r)
    {
        char *s = (char *)malloc(sizeof(char) * (strlen(base) + 1));
        strcpy(s, base);

        clock_t start_insert = clock();

        for (int i = 0; i < nb_insertions; ++i){
            bench_string_index(&s, base, index);
        }

        clock_t start_delete = clock();
        float insert_time = (float)(start_delete - start_insert) / CLOCKS_PER_SEC;

        printf("STR;%f;%zu\n", insert_time, nb_repetitions);
    }
}

//répétition au index different
int main__(){
    srand(time(NULL));

    const size_t nb_chars = 10000;
    const size_t nb_insertions = 1000;
    const size_t nb_repetitions = 5000;
    const int substring_size = 3;

    char *base = (char *)malloc(sizeof(char) * (1 + nb_chars));
    for (int i = 0; i < nb_chars; ++i)
    {
        base[i] = 'a' + (i % 25);
    }
    base[nb_chars] = '\0';

    printf("METHOD;INSERTION;REPETITION\n");
    for (int r = 0; r < 50; ++r)
    {
        Rope *rope = init_rope(base, substring_size); // TO DO
        assert(rope != NULL);
        clock_t start_insert = clock();
        for (int i = 0; i < nb_insertions; ++i){
            int index = rand() % strlen(base);
            rope_insert_at(rope, init_string(base), (unsigned int *) &index);
        }
        clock_t start_delete = clock();
        float insert_time = (float)(start_delete - start_insert) / CLOCKS_PER_SEC;
        printf("ROPE;%f;%zu\n", insert_time, nb_repetitions);
        rope_delete(rope);
    }
    //str
    for (int r = 0; r < 50; ++r)
    {
        char *s = (char *)malloc(sizeof(char) * (strlen(base) + 1));
        strcpy(s, base);

        clock_t start_insert = clock();

        bench_string(&s, base, nb_insertions);

        clock_t start_delete = clock();
        float insert_time = (float)(start_delete - start_insert) / CLOCKS_PER_SEC;

        printf("STR;%f;%zu\n", insert_time, nb_repetitions);
    }
}

//taille insertion différente
int main_dhz()
{
    srand(time(NULL));

    const size_t nb_insertions = 1000;
    const size_t nb_repetitions = 50;
    const int substring_size = 3;
    const size_t nb_chars = 10000;
    int index = 1000;

    char *base2 = (char *)malloc(sizeof(char) * (1 + nb_chars));
    for (int i = 0; i < nb_chars; ++i)
    {
        base2[i] = 'a' + (i % 25);
    }
    base2[nb_chars] = '\0';

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

        Rope *rope = init_rope(base2, substring_size); // TO DO

        clock_t start_create = clock();
        rope_insert_at(rope, init_string(base), (unsigned int *) &index);
        clock_t start_create2 = clock();

        float size = strlen(base);
        float insert_time = (float)(start_create2 - start_create) / CLOCKS_PER_SEC;
        printf("ROPE;%f;%f\n", insert_time, size);
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

        char *s = (char *)malloc(sizeof(char) * (strlen(base2) + 1));
        strcpy(s, base2);

        clock_t start_create = clock();
        bench_string_index(&s, base, index);
        clock_t start_delete = clock();
        float insert_time = (float)(start_delete - start_create) / CLOCKS_PER_SEC;
        float size = strlen(base);


        printf("STR;%f;%f\n", insert_time, size);
    }
    return 0;
}

//structure taille differente
int main()
{
    srand(time(NULL));

    const size_t nb_insertions = 1000;
    const size_t nb_repetitions = 50;
    const int substring_size = 3;
    const size_t nb_charsTMP = 10000;
    int index = 1000;

    char *base2 = (char *)malloc(sizeof(char) * (1 + nb_charsTMP));
    for (int i = 0; i < nb_charsTMP; ++i)
    {
        base2[i] = 'a' + (i % 25);
    }
    base2[nb_charsTMP] = '\0';

    printf("METHOD;INSERTION;NOMBRE_DE_CARACTERE\n");
    for (int r = 0; r < nb_repetitions; ++r)
    {
        size_t nb_chars = 1000000 * (r + 1);

        char *base = (char *)malloc(sizeof(char) * (1 + nb_chars));
        for (int i = 0; i < nb_chars; ++i)
        {
            base[i] = 'a' + (i % 25);
        }
        base[nb_chars] = '\0';

        Rope *rope = init_rope(base, substring_size); // TO DO

        clock_t start_create = clock();
        rope_insert_at(rope, init_string(base2), (unsigned int *) &index);
        clock_t start_create2 = clock();

        float insert_time = (float)(start_create2 - start_create) / CLOCKS_PER_SEC;
        printf("ROPE;%f;%zu\n", insert_time, nb_chars);
    }

    for (int r = 0; r < nb_repetitions; ++r)
    {
        size_t nb_chars = 1000000 * (r + 1);

        char *base = (char *)malloc(sizeof(char) * (1 + nb_chars));
        for (int i = 0; i < nb_chars; ++i)
        {
            base[i] = 'a' + (i % 25);
        }
        base[nb_chars] = '\0';

        char *s = (char *)malloc(sizeof(char) * (strlen(base) + 1));
        strcpy(s, base);

        clock_t start_create = clock();
        bench_string_index(&s, base2, index);
        clock_t start_delete = clock();
        float insert_time = (float)(start_delete - start_create) / CLOCKS_PER_SEC;


        printf("STR;%f;%zu\n", insert_time, nb_chars);
    }
    return 0;
}