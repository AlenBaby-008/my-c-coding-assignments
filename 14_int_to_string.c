/*
Write a C program that takes an integer from the user and converts it into a
string of characters.
Description:The program should prompt the user to enter a whole number. It must
then process this integer and store each of its digits as characters within a character
array (string). The resulting string should represent the number exactly as it was
entered, including a negative sign if the number is less than zero. Finally, the program
should display the resulting string on the screen.
*/


#include <stdio.h>
#include <stdbool.h>


void inttoString(int num, char string[])
{
    int i = 0, digit;
    bool negative = false;


    if (num == 0)
    {
        string[i++] = '0';
        string[i] = '\0';
        return;
    }


    long tempNum = num;


    if (tempNum < 0)
    {
        negative = true;
        tempNum = -tempNum;
    }


    while (tempNum > 0)
    {
        digit = tempNum % 10;
        string[i++] = (char)(digit + '0');
        tempNum /= 10;
    }


    if (negative)
    {
        string[i++] = '-';
    }

    string[i] = '\0';


    int start = 0, end = i - 1;
    char temp;

    while (start < end)
    {
        temp = string[start];
        string[start] = string[end];
        string[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    int num;
    char string[20];

    printf("Enter a whole number: ");
    scanf("%d", &num);

    inttoString(num, string);


    printf("Output string: \"%s\"\n", string);

    return 0;
}


