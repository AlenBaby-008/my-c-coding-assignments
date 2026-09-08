/*
18.Write a C program that takes an integer from the user and extracts (n) bits starting
from a specific bit position.
Description: The program should prompt the user to enter a number, a starting
position, and the number of bits to be retrieved. It must then isolate that specific
sequence of bits from the original value and display the resulting number on the
screen. The other bits in the number should not affect the final output.
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

unsigned int generateMask(unsigned int n)
{

    unsigned int mask;
    if (n >= 32)
    {
        return ~0U;
    }
    return (1U << n)-1;
}

int main()
{
    unsigned int num, position, range;


    printf("Enter a natural number: ");
    if (scanf("%u", &num) != 1) return 1;

    printf("Enter starting bit position: ");
    scanf("%u", &position);

    if (position >= 32)
    {
        printf("Position must be b/w 0 & 31");
        return 1;
    }

    printf("Enter no. of bits to be retrieved (n): ");
    scanf("%u", &range);

    if (position + range > 32)
    {
        printf("Position + Range must be b/w 0 & 31");
        return 1;
    }

    printf("\nOg Number: %u\n", num);
    printf("Binary of the og no.: ");
    binary(num);

    unsigned int mask = generateMask(range);
    printf("Binary of the mask: ");
    binary(mask);


    unsigned int shiftBits = num >> position;
    unsigned int result = shiftBits & mask;
    printf ("Binary of the result: ");
    binary(result);


    printf("Extracted bits in binary: ");
    for (int i = (int)range - 1; i >= 0; i--)
    {
        printf("%u", (result >> i) & 1);
    }

    printf("\nExtracted no.: %u\n", result);
    printf("\n");

    return 0;
}
