/*
Write a C program that takes a string from the user and reverses its characters using
an iterative approach.
Description: The program should prompt the user to enter a sequence of characters. It
must then swap or move the characters within the string using a loop until the entire
string is reversed. The final resulting string should be displayed on the screen.
*/


#include <stdio.h>
#include <string.h>


void stringReverse(char str[])
{
    int start = 0, end = strlen(str) - 1;


    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

int main() 
{
    char string[50];


    printf("Enter a string: ");
    fgets(string, sizeof(string), stdin);



    string[strcspn(string, "\n")] = '\0';

    stringReverse(string);

    printf("Reversed string: %s\n", string);

    return 0;
}
