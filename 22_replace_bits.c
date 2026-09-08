/*
Write a C program that takes a number and replaces n of its bits, starting from a
given position, with another set of n bits from a second number.
Description: The program should prompt the user to enter two integers, a starting bit
position, and the number of bits n to be modified. It must then clear $n$ bits in the
first number at the specified position and replace them with the corresponding $n$
bits from the second number. The final resulting value should be displayed on the
screen while all other bits in the first number remain unchanged.
*/



#include <stdio.h>

void binary(unsigned int num)
{
    for (int i = 31; i >= 0; i--)
    {
        unsigned int bit = (num >> i) & 1;
        printf("%u", bit);
        if (i % 4 == 0) printf(" ");
    }
    printf("\n\n");
}

unsigned int replaceBits(unsigned int num1, unsigned int num2, unsigned int pos, unsigned int n)
{
    unsigned int mask;

    mask = (1U << n) - 1;

    printf ("Mask :");
    binary(mask);


    unsigned int clearMask = ~(mask << pos);

    printf ("Cleared mask :");
    binary(clearMask);

    unsigned int clearedNumber1 = num1 & clearMask;

    printf ("Cleared Number1 (Number 1 * Cleared mask) :");
    binary(clearedNumber1);


    unsigned int replacementBits = (num2 & mask) << pos;

    printf ("Replacement bits ((Number 2 * Mask) << Position)) :");
    binary(replacementBits);

    return clearedNumber1 | replacementBits;
}

int main()
{
    unsigned int number1, number2, position, range;

    printf("Enter the first number: ");
    if (scanf("%u", &number1) != 1) return 1;

    printf("Enter the second number: ");
    if (scanf("%u", &number2) != 1) return 1;

    printf("Enter starting bit position:  ");
    scanf("%d", &position);
    if (position >= 32)
    {
        printf("Position must be b/w 0 and 31.");
        return 1;
    }

    printf("Enter number of bits to replace (n): ");
    scanf("%d", &range);
    if( position + range > 32)
    {
        printf("Position + n must not exceed 32.");
        return 1;
    }


    printf("\nFirst Number: %u\n", number1);
    printf("Binary of 1st: ");
    binary(number1);

    printf("\nSecond Number:  %u\n", number2);
    printf("Binary of 2nd: ");
    binary(number2);

    unsigned int result = replaceBits(number1, number2, position, range);


    printf("Output no. in binary: ");
    binary(result);
    printf("\nOutput Number: %u\n", result);

    return 0;
}
  
