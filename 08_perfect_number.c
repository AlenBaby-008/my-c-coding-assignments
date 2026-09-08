/*
Write a C program that uses a function to check whether a given number is a
Perfect Number.
Description: The program should prompt the user to enter a positive integer. A
separate function must be written that computes the sum of all proper divisors of the
number (excluding the number itself) and returns whether the sum equals the original
number. The main function should display whether the number is perfect or not.
(Example: 6 = 1+2+3, 28 = 1+2+4+7+14)
*/




#include <stdio.h>
#include <stdbool.h>

bool perfect(int num)
{
    if (num <= 1)
    {
        return false;
    }

    int sum = 0;

    for (int i = 1; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            sum += i;
        }
    }

    return sum == num;
}

int main() 
{
    int number;

    printf("Enter a positive integer : ");
    scanf("%d", &number);

    if (perfect(number))
    {
        printf("%d is a Perfect number.", number);
    }
    else
    {
        printf("%d is not a Perfect number.", number);
    }

    return 0;
}
