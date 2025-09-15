#include <stdio.h>
#include <stdlib.h>
#include "stringFunctions.h"
#include "io.h"
#include "workWithPointers.h"

const long int ebanieElementi = 176813;        //без EOF пока что
const int countOfStrings = 5313;

//пох на неналичие \0
//количество строк 5313 длину строки определяем через разность соседних указателей

int main()
{
    FILE *file = fopen("oneg.txt", "r");

    if (file == NULL)
    {
        printf("We can't open this file");
        return -1;
    }

    //char array[15][42] = {};       // инициализируем все нулями
    //char temp[42] = {0};           // инициализируется нулевыми значениями при создании чтобы можно было заменить строку макс размера

    char ebanutayaString [ebanieElementi] = {0};

    inputElementsToBigSmoke(ebanieElementi, ebanutayaString, file);

    char* pointersToLines[countOfStrings] = {NULL};     //если 1* и [] - когда передаем значение в ф-ию то будем писать char**

    getStringPointers(ebanutayaString, pointersToLines, ebanieElementi);

    outputFromPointers(countOfStrings, pointersToLines);

    fclose(file);
    return 0;       // полезно чтобы после каждой проги возвращался 0


    // int count = countOfLines(file);
    // printf("%d\n", count);

    //rewind(file);       // потому что файл уже был прочитан и указатель на файл находился в конце

    // size_t maxLenOfString = maxLen(file) + 1;
    // printf("%zu", maxLenOfString);

    // for (int i = 0; i <= 14; i++)
    // {
    //     fgets(array[i], 42, file);
    // }

    // strswap(temp, array[0], array[1]);
    // strswapLetter(array[0], array[1]);
    // strswapInt(array[0], array[1]);
}



