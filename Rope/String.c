//
// Created by toum on 10/16/23.
//

#include "String.h"
#include <stdlib.h>
#include <string.h>

// Create a string
String* init_string(char *string){
  String* s = malloc(sizeof (String));
  s->first_char = string;
  s->size = strlen(string);
  return s;
};

// Free the string
void free_string(String * string){
    if (string == NULL){return;}
    free(string->first_char);
    free(string);
}

// Cut a String in half
// Return the right part of the string
// The input string will be changed to become the left part
String * cut_string(String* string) {
    unsigned int rest = string->size & 1;
    string->size >>= 1;
    String* right_part = malloc(sizeof(String));
    right_part->first_char = string->first_char + string->size;
    right_part->size = string->size + rest;
    return right_part;
}
