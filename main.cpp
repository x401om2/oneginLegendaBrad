#include <stdio.h>
#include <stdlib.h>
#include "stringFunctions.h"

//*array[0]

const int ebanieElementi = 186124;          //без EOF пока что


int main()
{
    FILE *file = fopen("text.txt", "r");

    char array[15][42] = {};       // инициализируем все нулями
    char temp[42] = {0}; // инициализируется нулевыми значениями при создании чтобы можно было заменить строку макс размера

    long int ebanutayaString[ebanieElementi] = {0};

    if (file == NULL)
    {
        printf("We can't open this file");
        return -1;
    }

    for (int i = 0; i <= ebanieElementi; i++)
    {
        ebanutayaString[i] = getc(file);
    }
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

    // for (int j = 0; j <= 14; j++)
    // {
    //     printf("%s", array[j]);
    // }

    fclose(file);
    return 0;       // полезно чтобы после каждой проги возвращался 0
}



