#include "workWithPointers.h"
#include <stdlib.h>
#include <string.h>

void getStringPointers(char* ebanutayaString, char** pointersToLines, long int ebanieElementi)
{
    pointersToLines[0] = ebanutayaString;
    int counters = 1;

    for (long int karetka = 0; karetka < ebanieElementi - 1; karetka++)
    {
        if ((ebanutayaString[karetka] == '\0') && (ebanutayaString[karetka+1] != '\0'))
        {
            pointersToLines[counters] = &ebanutayaString[karetka+1];
            counters++;
        }
    }
}
