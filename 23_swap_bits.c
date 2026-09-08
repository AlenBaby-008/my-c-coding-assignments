/*
Write a C program that takes two integers and swaps n bits starting from a given
position in both numbers.
Description: The program should prompt the user to enter two integers, a starting bit
position, and the number of bits (n) to be swapped. It must then exchange the n
consecutive bits at the specified position between the two numbers — the bits from
the first number go into the second, and vice versa — while all remaining bits in both
numbers stay exactly as they were. Both final values should be displayed on the
screen after the swap.
*/


#include <stdio.h>


void binary(unsigned int number)
{
    for (int i = 31; i >= 0; i--)
    {
        unsigned int bit = (number >> i) & 1;
        printf("%u", bit);
        if (i % 4 == 0) printf(" ");
    }
    printf("\n");
}

void bitsSwap(unsigned int *number1, unsigned int *number2, int position, int range) {

    unsigned int mask;

    mask = (1U << range) - 1;

    mask = mask << position;
    printf("\nMask bit: ");
    binary(mask);

    unsigned int xor = (*number1 ^ *number2);
    printf("\nXOR bit (Number1 ^ Number2): ");
    binary(xor);

    unsigned int xorDiff = xor & mask;
    printf("\nXOR difference bit (XOR bit & mask): ");
    binary(xorDiff);

    *number1 ^= xorDiff;
    *number2 ^= xorDiff;
}

int main()
{
    unsigned int num1, num2,pos, n;


    printf("Enter first integer: ");
    if (scanf("%u", &num1) != 1) return 1;

    printf("Enter second integer: ");
    if (scanf("%u", &num2) != 1) return 1;

    printf("Enter starting bit position : ");
    scanf("%d", &pos);
    if(pos >= 32)
    {

        printf("Must be between 0 and 31.");
        return 1;
    }

    printf("Enter number of bits to swap (n): ");
    scanf("%d", &n);
    if(pos + n > 32)
    {
        printf("position + n must not exceed 32.");
        return 1;
    }


    printf("\n----- Before Swapping -----\n");
    printf("num1: %10u | ", num1);
    binary(num1);
    printf("num2: %10u | ", num2);
    binary(num2);


    bitsSwap(&num1, &num2, pos, n);

    printf("\n----- After Swap -----\n");
    printf("num1 (XOR difference ^ Number1): %10u | ", num1);
    binary(num1);
    printf("num2 (XOR difference ^ Number2): %10u | ", num2);
    binary(num2);

    return 0;
}
