/*
Write a C program that uses functions to convert a decimal number to any base
between 2 and 16.
Description: The program should prompt the user to enter a decimal number and a
target base. A separate function must be written that performs the repeated division
method, stores each remainder, and builds the result in the correct order. For bases
above 9, remainders 10–15 should be represented as letters A–F. The converted value
should be displayed from the main function.
*/




#include <stdio.h>
#include <string.h>

void decimaltoBase(int decimal, int base, char result[])
{
    char digits[] = "0123456789ABCDEF", temp[66];

    int index = 0, negative = 0, remainder;


    if (decimal == 0)
    {
        result[0] = '0';
        result[1] = '\0';
        return;
    }


    if (decimal < 0)
    {
        negative = 1;
        decimal = -decimal;
    }


    while (decimal > 0)
    {
        remainder = decimal % base;
        temp[index++] = digits[remainder];
        decimal /= base;
    }


    if (negative)
    {
        temp[index] = '-';
        index++;
    }

    for (int i = 0; i < index; i++)
    {
        result[i] = temp[index -1- i];
    }
    result[index] = '\0';
}

int main()
{
    int decimal, base;
    char result[66];

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);


    printf("Enter target base (2-16): ");
    scanf("%d", &base);
    if (base < 2 || base > 16)
    {
        printf("The base is invalid.");
        return 1;
    }

    decimaltoBase(decimal, base, result);


    printf("The converted value of %d in base %d is: %s\n", decimal, base, result);

    return 0;
}
