/*
Write a C program that rearranges an array such that all negative numbers
appear before all positive numbers while preserving the relative order of both
groups.
Description: The program should prompt the user to enter the size of the array and its
elements (a mix of positive and negative integers). It must then rearrange the elements
so that all negative numbers come first, followed by all positive numbers, without
changing the order in which the negatives appear among themselves or the positives
among themselves. Zero can be treated as positive. The rearranged array should be
displayed on the screen.
*/



#include <stdio.h>

void rearrangeNegativesFirst(const int arr[], int n, int resultingArray[])
{
    int position = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            resultingArray[position++] = arr[i];
        }
    }

    for (int i = 0; i < n; i++)
    {

        if (arr[i] >= 0)
        {
            resultingArray[position++] = arr[i];
        }
    }
}

int main()
{
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int array[size];
    int rearrangedArray[size];

    printf("Enter %d element(s) ( +ve & -ve integers):\n", size);
    for (int i = 0; i < size; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("\nOriginal Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    rearrangeNegativesFirst(array, size, rearrangedArray);

    printf("Rearranged Array : ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", rearrangedArray[i]);
    }
    printf("\n");

    return 0;
}
