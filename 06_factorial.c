/*
Write a C program that takes a positive integer from the user and calculates its
factorial.
Description: The program should prompt the user to enter a single whole number. It
must then calculate the factorial of that number, which is the product of all positive
integers from 1 up to the number entered. The final result should be displayed clearly
on the screen. The program should also account for the fact that the factorial of 0 is
*/



#include <stdio.h>

int main()
{
    int num;
    unsigned long fact = 1;


    printf("Enter a natural number: ");


    if (scanf("%d", &num) == 0)
    {
        printf("The number is invalid.");
        return 1;
    }


    if (num < 0)
    {
        printf("For -ve number, factorial is undefined.");
        return 1;
    }

    for (int i = 2; i <= num; i++)
    {
        fact *= i;
    }


    printf("The factorial of %d is %lu.", num, fact);

    return 0;
}
