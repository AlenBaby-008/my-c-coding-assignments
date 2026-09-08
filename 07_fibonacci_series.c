/*
Write a C program to generate the Fibonacci series up to a given number of terms.
Description: The program should prompt the user to enter the number of terms (n). It
should then generate the Fibonacci sequence, where each number is the sum of the
two preceding ones, starting from 0 and 1. The program must display the sequence up
to the specified number of terms.
*/



#include <stdio.h>

int main()
{
    int num_of_terms;
    unsigned long num1 = 0, num2 = 1, nextNum;


    printf("Enter the no. of terms: ");


    if (scanf("%d", &num_of_terms) != 1)
    {
        printf("The no. is invalid");
        return 1;
    }


    if (num_of_terms <= 0)
    {
        printf("The no. of terms must be +ve");
        return 1;
    }

    printf("Fibonacci Series of %d number of terms: \t", num_of_terms);

    for (int i = 1; i <= num_of_terms; i++)
    {
        printf("%lu", num1);


        if (i < num_of_terms)
        {
            printf(" , ");
        }


        nextNum = num1 + num2;
        num1 = num2;
        num2 = nextNum;
    }


    return 0;
}
