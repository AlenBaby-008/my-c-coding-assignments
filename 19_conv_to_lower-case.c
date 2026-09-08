/*
Write a C program that takes a string from the user and converts all uppercase letters
into their corresponding lowercase letters.
Description: The program should prompt the user to enter a sequence of characters. It
must then check each character individually. If a character is an uppercase letter, the
program should convert it to its lowercase equivalent. If the character is already
lowercase or is not a letter at all, the program should leave it exactly as it is. The final
modified string should be displayed on the screen.
*/


#include <stdio.h>
#include <string.h>

void lowerCase(char sentence[])
{
    for (int i = 0; sentence[i] != '\0'; i++)
    {
        if (sentence[i] >= 'A' && sentence[i] <= 'Z')
        {
            sentence[i] = sentence[i] + ('a' - 'A');
        }
    }
}

int main()
{
    char sentence[2000];

    printf("Enter a sentence: ");

    fgets(sentence, sizeof(sentence), stdin);

    sentence[strcspn(sentence, "\n")] = '\0';

    lowerCase(sentence);

    printf("\nLowercase : %s\n", sentence);

    return 0;
}
