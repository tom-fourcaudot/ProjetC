//
// Created by toum on 10/16/23.
//

#include "String.h"
#include <stdlib.h>
#include <string.h>

String* init_string(char *string){
  String* s = malloc(sizeof (String));
  s->first_char = string;
  s->size = strlen(string);
  return s;
};

void free_string(char* first_char, int sizeOfString){
    free((void*)first_char + (sizeOfString * sizeof(char)));
    free(first_char);
}