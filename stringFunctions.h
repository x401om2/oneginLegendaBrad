#ifndef STRING_FUNCTIONS
#define STRING_FUNCTIONS

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strswapInt(char* strOne, char* strTwo);
void strswap(char* temp, char* strOne, char* strTwo);
void strswapLetter(char* firstLetter, char* secondLetter);

ssize_t getlineMaximaKatkova(char** ptr_string, size_t* ptr_size, FILE* stream);

size_t maxLen(FILE* stream);
int countOfLines(FILE* stream);

#endif
