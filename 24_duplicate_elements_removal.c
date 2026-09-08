/*
Write a C program to remove duplicate elements from a given array.
Description: The program should prompt the user to enter the size of the array and its
elements. It must then identify and remove any duplicate values, ensuring that each
element appears only once in the resulting array. The program should finally display
the updated array containing only unique elements.
*/


#include <stdio.h>
#include <stdbool.h>

int duplicateRemoval(int array[], int size)
{
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        bool duplicate = false;
        for (int j = 0; j < count; j++)
        {
            if (array[i] == array[j])
            {
                duplicate = true;
                break;
            }
        }

        if (!duplicate)
        {
            array[count] = array[i];
            count++;
        }
    }

    return count;
}

int main()
{
    int size;

    printf("Enter the size of the array (enter a +ve no.): ");
    if (scanf("%d", &size) != 1 || size <= 0) return 1;

    int array[size];

    printf("Enter %d element(s):\n", size);
    for (int i = 0; i < size; i++)
    {
        printf("Element %d: ", i + 1);
        if (scanf("%d", &array[i]) != 1) return 1;
    }

    printf("\nOg array with %d elements: ", size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    int withoutdupSize = duplicateRemoval(array, size);

    printf("New Array with %d elements: ", withoutdupSize);

    for (int i = 0; i < withoutdupSize; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
