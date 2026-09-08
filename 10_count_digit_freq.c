/* 
Write a C program that uses a function to count the frequency of each digit (0–9)
in a given integer.
Description: The program should prompt the user to enter an integer. A separate
function must be written that takes the number, extracts each digit using a loop, and
updates a frequency array accordingly. The function should not return a single value
but instead update the array directly. The main function should then print how many
times each digit appears in the number.
*/



#include <stdio.h>

void digitFrequency(long long num, int frequency[])
{

    if (num < 0)
    {
        num = -num;
    }


    if (num == 0)
    {
        frequency[0]++;
        return;
    }

    while (num > 0)
    {
        int digit = num % 10;
        frequency[digit] = frequency[digit] + 1;
        num /= 10;
    }
}

int main()
{
    long long num;
    int freq[10] = {0};

    printf("Enter an integer: \n");

    scanf("%lld", &num);

    digitFrequency(num, freq);

    printf("\nDigit Frequency for %lld : \n\n", num);
    for (int i = 0; i < 10; i++)
    {
        printf("Digit %d is %d time (s)\n", i, freq[i]);
    }

    return 0;
}

