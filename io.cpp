#include "io.h"
#include <stdio.h>

void outputFromPointers(int countOfStrings, char** pointersToLines)
{
    for (int output = 0; output < countOfStrings - 1; output++)
    {
        char* pointerFirst = pointersToLines[output];
        char* pointerSecond = pointersToLines[output + 1];

        for (int index = 0; index < (pointerSecond - pointerFirst); index++)
        {
            printf("%c", *(pointerFirst + index));
        }
    }
}

void outputForOneSymbol(long int ebanieElementi, char* ebanutayaString)
{
    for (long int j = 0; j < ebanieElementi; j++)
    {
        printf("%c", ebanutayaString[j]);
    }
}

void inputElementsToBigSmoke(long int ebanieElementi, char* ebanutayaString, FILE* file)
{
    for (int i = 0; i < ebanieElementi; i++)
    {
        ebanutayaString[i] = getc(file);
    }
}
