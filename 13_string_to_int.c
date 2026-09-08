/*
Write a C program that takes a string of digits from the user and converts it into its equivalent
integer value.
Description:The program should prompt the user to enter a number as a string (for example,
"1234"). It must then process this string character by character and transform it into an actual
integer variable that can be used for mathematical operations. The program should be able to
handle positive numbers and display the final integer result on the screen.
*/

#include <stdio.h>
#include <stdbool.h>


int stringtoInt(const char string[], bool *valid)
{
    int output = 0;
    int i = 0;

    *valid = true;

    if (string[0] == '+')
    {
        i++;
    }

    if (string[i] == '\0')
    {
        *valid = false;
        return 0;
    }


    while (string[i] != '\0')
    {

        if (string[i] >= '0' && string[i] <= '9')
        {

            int digit = string[i] - '0';

            output = output * 10 + digit;
        }
        else
        {
            *valid = false;
            return 0;
        }
        i++;
    }

    return output;
}

int main()
{
    char string[50];
    bool valid;


    printf("Enter a string of digits: ");
    scanf("%49s", string);

    int num = stringtoInt(string, &valid);

    if (!valid)
    {
        printf("Error, input is invalid");
        return 1;
    }

    printf("Converted Integer value: %d\n", num);


    printf("Mathematical checking (%d + 100): %d\n", num, num + 100);

    return 0;
}
