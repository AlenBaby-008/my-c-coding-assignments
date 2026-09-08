/* 
Write a C program that uses a recursive function to find the GCD of two
numbers using the Euclidean algorithm.
Description: The program should prompt the user to enter two positive integers. A
recursive function must be written that repeatedly applies the Euclidean method
replacing the larger number with the remainder of dividing the two until the
remainder is zero. The GCD should be returned to the main function and displayed on
the screen.
*/



#include <stdio.h>


int GCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return GCD(b, a % b);
}

int main()
{
    int num1, num2, gcd;


    printf("Enter two positive integers: ");

    scanf("%d %d", &num1, &num2);


    gcd = GCD(num1, num2);


    printf("GCD of %d & %d is %d. ", num1, num2, gcd);

    return 0;
}
