
/*
a C program that takes a string from the user and checks whether it is a
palindrome.
Description: The program should prompt the user to enter a string. It must determine
if the string reads the same forward and backward. The program should then display a
message to the user stating whether the input is a palindrome or not.
*/


#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool palindrome(const char string[])
{
    int start = 0,end = strlen(string) - 1;

    while (start < end)
    {
        if (string[start] != string[end])
        {
            return false;
        }
        start++;
        end--;
    }

    return true;
}

int main()
{
    char string[50];

    printf("Enter a string: ");
    if (fgets(string, sizeof(string), stdin) == NULL)
    {
        printf("Error");
        return 1;
    }

    string[strcspn(string, "\n")] = '\0';


    if (palindrome(string))
    {
        printf("\"%s\" is a palindrome.", string);
    } else
    {
        printf("\"%s\" is not a palindrome.", string);
    }

    return 0;
}
