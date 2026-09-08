/*
Write a C program that takes a string from the user and replaces every sequence of
multiple consecutive spaces with a single space.
Description: The program should prompt the user to enter a sentence that may
contain several spaces between words. It must then process the string to ensure that
any instance where two or more blank spaces appear together is reduced to just one
blank space. The final cleaned string should be displayed on the screen.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void deleteSpaces(char string[])
{
    int read = 0, write = 0;
    bool space = false;

    while (string[read] != '\0')
    {
        if (string[read] != ' ')
        {
            string[write++] = string[read];
            space = false;
        }
        else
        {
            if (!space)
            {
                string[write++] = ' ';
                space = true;
            }
        }
        read++;
    }
    string[write] = '\0';
}

int main()
{
    char str[2000];

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    deleteSpaces(str);

    printf("\n\nOutput string: \"%s\"\n\n", str);

    return 0;
}
