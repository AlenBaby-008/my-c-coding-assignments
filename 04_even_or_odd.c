/* 
Write a C program that takes an integer from the user and determines whether
the number is even or odd.
Description: The program should prompt the user to enter a whole number. It must
then check if the number is perfectly divisible by 2. If it is, the program should
display that the number is even; otherwise, it should display that the number is odd.
The program should handle both positive and negative integers.
*/



#include <stdio.h>

int main() 
{
    int num;

    printf("Enter a whole number: ");
    
    if (scanf("%d", &num) == 0)
    {
        printf("The number is invalid");
        return 0;
    }

    if (num % 2 == 0)
    {
        printf("%d is an even number.\n", num);
    }

    else
    {
        printf("%d is an odd number.", num);
    }

    return 0;
}
