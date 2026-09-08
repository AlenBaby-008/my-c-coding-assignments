/*
Write a C program that takes a number and toggles a specific number of bits (n)
starting from a given position.
Description: The program should prompt the user to enter an integer, a starting bit
position, and the number of bits to be modified. It must then change the state of those
(n) consecutive bits—switching 0s to 1s and 1s to 0s—while keeping all other bits in
the number exactly as they were. The final value of the number after the toggle
operation should be displayed on the screen.
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
    printf("\n");
}


unsigned int toggleBits(unsigned int num, int position, int range)
{


    unsigned int mask;
    if (range >= 32)
    {
        mask = ~0U;
    }
    else
    {
        mask = (1U << range) - 1;
    }


    mask = mask << position;

    return mask;
}

int main()
{
    unsigned int num,position,range;


    printf("Enter a whole number: ");
    scanf("%u", &num);

    printf("Enter starting bit position: ");
    scanf("%u", &position);
    if (position >= 32)
    {
        printf("Position should be b/w 0 and 31.");
        return 1;
    }

    printf("Enter no. of bits to toggle (n): ");
    if (scanf("%u", &range) != 1 || position + range > 32)
    {
        printf("Invalid . (position + n) should not exceed 32.");
        return 1;
    }

    printf("\nOriginal Number: %u\n\n", num);
    printf("Binary of the orginal: ");
    binary(num);


    unsigned int mask = toggleBits(num, position, range);

    printf("Binary of the mask: ");
    binary(mask);

    unsigned int result = num ^ mask;


    printf("Binary of the result: ");
    binary(result);
    printf("\nResult : %u\n", result);

    return 0;
}
