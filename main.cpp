#include <stdio.h>
#include <stdlib.h>
#include "stringFunctions.h"
#include "io.h"
#include "workWithPointers.h"
#include "sorting.h"

const long int ebanieElementi = 176813;        //c пом ф-ий из strFunctions посчитано
const int countOfStrings = 5313;

int main()
{
    FILE *file = fopen("oneg.txt", "r");

    if (file == NULL)
    {
        printf("We can't open this file");
        return -1;
    }

    char ebanutayaString [ebanieElementi] = {0};

    inputElementsToBigSmoke(ebanieElementi, ebanutayaString, file);

    changing(ebanieElementi, ebanutayaString);

    char* pointersToLines[countOfStrings] = {NULL};     //если 1* и [] - когда передаем значение в ф-ию то будем писать char**

    getStringPointers(ebanutayaString, pointersToLines, ebanieElementi);

    // bubbleSortPolnoeGovnoNapisal(pointersToLines, countOfStrings);

    qsort(pointersToLines, countOfStrings, sizeof(char*), (int (*)(const void*, const void*))compareStringReversed);

    // outputFromPointers(countOfStrings, pointersToLines);
    simpleOutput(pointersToLines, countOfStrings);

    fclose(file);

    return 0;

}
