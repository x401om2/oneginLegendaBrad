#include "workWithPointers.h"

void getStringPointers(char* ebanutayaString, char** pointersToLines, long int ebanieElementi)
{
    pointersToLines[0] = ebanutayaString;
    int counters = 1;

    for (long int karetka = 0; karetka < ebanieElementi; karetka++)
    {
        if (ebanutayaString[karetka] == '\n')
        {
            pointersToLines[counters] = &ebanutayaString[karetka+1];
            counters++;
        }
    }
}
