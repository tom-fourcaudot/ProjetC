//
// Created by toum on 10/16/23.
//

#ifndef PROJETC_STRING_H
#define PROJETC_STRING_H
typedef struct String String;
struct String {
    char* first_char;
    unsigned int size;
};

String* init_string(char* string);
void free_string(String *string);
String* cut_string(String* string);
#endif //PROJETC_STRING_H
