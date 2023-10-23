//
// Created by toum on 10/16/23.
//

#include "String.h"
#include <stdlib.h>
#include <string.h>

String init_string(char* string[]){
  String* s = malloc(sizeof (String));
  s->first_char = string[0];
  s->size = strlen((const char *) string);
  return *s;
};

