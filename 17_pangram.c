/*
Write a C program that takes a string input from the user and determines whether it is
a pangram or not.
Description: The program should prompt the user to enter a sentence or a string of
characters. It must then verify if every letter of the alphabet from A to Z appears at
least once within the provided text, regardless of whether the letters are uppercase or
lowercase. The final output should state if the string is a pangram.
*/

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>


bool pangram(const char string[])
{
    bool alphabet[26] = {false};
    int i, index, count = 0;

    for ( i = 0; string[i] != '\0'; i++)
    {

        char letter = (char)tolower((unsigned char)string[i]);

        if (letter >= 'a' && letter <= 'z')
        {
            index = letter - 'a';


            if (!alphabet[index])
            {
                alphabet[index] = true;
                count++;

                if (count == 26)
                {
                    return true;
                }
            }
        }
    }

    return count == 26;
}

int main()
{
    char str[500];

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    if (pangram(str))
    {
        printf("\n\"%s\"----> is a pangram.", str);
    }
    else
    {
        printf("\n\"%s\"----> not a pangram.", str);
    }

    return 0;
}
