#include "sorting.h"
#include <stdio.h>
#include <string.h>


void bubbleSortPolnoeGovnoNapisal(char** pointersToLines, int countOfStrings)         //fuckingSLaveSort from luti bitches
{
    char* temp = NULL;
    for (int counter = 0; counter < countOfStrings - 1; counter++)
    {
        for (int i = 0; i < countOfStrings - 1; i++)
        {
            if (pointersToLines[i] != NULL && pointersToLines[i + 1] != NULL)
            {
                if (strcmp(pointersToLines[i], pointersToLines[i + 1]) > 0)
                {
                    temp = pointersToLines[i];
                    pointersToLines[i] = pointersToLines[i + 1];
                    pointersToLines[i + 1] = temp;
                }
            }
            else if (pointersToLines[i] == NULL && pointersToLines[i + 1] != NULL)
            {
                temp = pointersToLines[i];
                pointersToLines[i] = pointersToLines[i + 1];
                pointersToLines[i + 1] = temp;
            }
        }
    }
}


// strcmp которая не будет учитывать не буквы
// стркмп реверсд чтобы точно не обращала внимания на регистр проверить


int strcmpReversed(char* str1, char* str2)
{
    if (str1 == NULL || str2 == NULL) {         // работа с NULL вызовет segfault
        return 0;
    }

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int i = len1 - 1;                           // индексы на ласт символ не считая \0
    int j = len2 - 1;

    while (i >= 0 && j >= 0) {
        if (str1[i] != str2[j]) {
            return str1[i] - str2[j];           // bcd и xyz - разное => вернется 'd' - 'z' отрицательное (по таблице кодов ascii)
        }
        i--;
        j--;
    }

    if (i >= 0) {
        return 1;
    } else if (j >= 0) {
        return -1;
    } else {
        return 0;
    }
}

int compareStringReversed(void *str1, void *str2) {
    if (str1 == NULL && str2 == NULL) return 0;
    if (str1 == NULL) return -1;
    if (str2 == NULL) return 1;

    return strcmpReversed(*(char**)str1, *(char**)str2);        // (char**) приводим void* к нужному нам типу
}                                                               // *(char**)str1 - разыменовываем указатель чтобы получить то на что он указывает
