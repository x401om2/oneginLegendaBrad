#include "stringFunctions.h"
#include <stdio.h>

#include <stdbool.h>
#include <assert.h>
#include <ctype.h>

const int first_buffer_size = 256;
const int grow_buffer_coefficient = 2;

//больше инфы функции не void
void strswap(char* temp, char* strOne , char* strTwo)
{
    assert(temp != NULL);
    assert(strOne != NULL);
    assert(strTwo != NULL);

    strcpy(temp, strOne);
    strcpy(strOne, strTwo);
    strcpy(strTwo, temp);

}

void strswapLetter(char* firstLetter, char* secondLetter)
{
    assert(firstLetter != NULL);
    assert(secondLetter != NULL);

    char temp = '\0';
    int flag = 0;

    for (int i = 0; flag < 2; i++)
    {
        temp = *firstLetter;

        if (temp == '\n')
            flag += 1;

        *firstLetter = *secondLetter;

        if (*firstLetter == '\n')
            flag += 1;

        *secondLetter = temp;

        if (flag == 2)
            break;

        firstLetter++;
        secondLetter++;
    }
}

void strswapInt(char* strOne, char* strTwo)
{
    assert(strOne != NULL);
    assert(strTwo != NULL);

    int tempInt = 0;

    long int endPositionOne = strchr(strOne, '\n') + 1 - strOne;
    long int endPositionTwo = strchr(strTwo, '\n') + 1 - strTwo;

    long int maxPosition = (endPositionOne > endPositionTwo) ? endPositionOne : endPositionTwo;

    long unsigned int intIterations = maxPosition / sizeof(int);
    long int charIterations = maxPosition % sizeof(int);

    for (long unsigned int i = 0; i < intIterations; i++)
    {
        tempInt = *((int*) strOne);
        *((int*) strOne) = *((int*) strTwo);
        *((int*) strTwo) = tempInt;

        strOne += sizeof(int);
        strTwo += sizeof(int);
    }

    char tempChar = 0;

    for (int k = 0; k < charIterations; k++)
    {
        tempChar = *strOne;
        *strOne = *strTwo;
        *strTwo = tempChar;

        strOne++;
        strTwo++;
    }

}

ssize_t getlineMaximaKatkova(char** ptr_string, size_t* ptr_size, FILE* stream)
{
    if (ptr_string == NULL || ptr_size == NULL || stream == NULL)
        return -1;

    char* buffer = *ptr_string;
    size_t size = *ptr_size;

    if  (buffer == NULL)
    {
        size = first_buffer_size;
        buffer = (char*) calloc(size, sizeof(char));
        if (buffer == NULL)
            return -1;
    }
    else
    {
        if (size == 0)
            return -1;
    }


    size_t length = 0;
    int symbol = '\0';

    while ((symbol = fgetc(stream)) != EOF)
    {
        if (length == size - 1)
        {
            size_t new_size = size * grow_buffer_coefficient;
            // buffer = realloc(*ptr_string, size); //ptr_string = realloc(///)
            char* check_buf = (char*) realloc(buffer, new_size);
            if (check_buf == NULL)
            {
                *ptr_size = size;
                *ptr_string = buffer;

                return -1;
            }

            buffer = check_buf;
            size = new_size;
        }

        buffer[length++] = symbol;

        if (symbol == '\n')
            break;
    }

    if (length == 0 && symbol == EOF)
        return -1;

    if (length == size)
    {
        size_t new_size = length + 1;
        char* check_buf = (char*) realloc(buffer, new_size);
        if (check_buf == NULL)
        {
            *ptr_size = size;
            *ptr_string = buffer;

            return -1;
        }
        buffer = check_buf;
        size = new_size;
    }

    // Завершаем строку нулем
    buffer[length] = '\0';

    // Обновляем указатели
    *ptr_string = buffer;
    *ptr_size = size;
    return length;
}

int countOfLines(FILE* stream)
{
    int count = 0;
    size_t size = 10;
    char* string = NULL;

    while (getlineMaximaKatkova(&string, &size, stream) != -1)
    {
        count++;
    }

    return count;
}

size_t maxLen(FILE* stream)
{
    size_t stringSize = 10;
    size_t maxLenght = 0;

    char* string = NULL;

    while (getlineMaximaKatkova(&string, &stringSize, stream) != -1)
    {
        size_t current = strlen(string);

        if (current >= maxLenght)
        {
            maxLenght = current;
        }
    }

    return maxLenght;
}

void changing(long int ebanieElementi, char* ebanutayaString)
{
    for (int i = 0; i < ebanieElementi; i++)
    {
        if (ebanutayaString[i] == '\n')
        {
            ebanutayaString[i] = '\0';
        }
    }
}
