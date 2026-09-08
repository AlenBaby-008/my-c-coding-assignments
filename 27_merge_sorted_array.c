/*
Write a C program that merges two sorted arrays into a single sorted array
without using any sorting function.
Description: The program should prompt the user to enter the sizes and elements of
two arrays, each already sorted in ascending order. It must then merge them into a
third array by comparing elements from both arrays one by one and placing the
smaller element first, continuing until all elements are placed. The final merged sorted
array should be displayed on the screen.
*/



#include <stdio.h>

void mergeSortedArrays(const int a1[], int s1, const int a2[], int s2, int m[])
{
    int i = 0;
    int j = 0;
    int k = 0;


    while (i < s1 && j < s2)
    {
        if (a1[i] <= a2[j])
        {
            m[k++] = a1[i++];
        }
        else
        {
            m[k++] = a2[j++];
        }
    }

    while (i < s1)
    {
        m[k++] = a1[i++];
    }

    while (j < s2)
    {
        m[k++] = a2[j++];
    }
}

int main()
{
    int size1, size2;

    printf("Enter the size of the 1st sorted array: ");
    if (scanf("%d", &size1) != 1 || size1 <= 0) return 1;

    int array1[size1];
    printf("Enter %d sorted elements for the 1st array:\n", size1);
    for (int i = 0; i < size1; i++)
    {
        printf("array1[%d]: ", i);
        scanf("%d", &array1[i]);
    }
    printf("\nEnter the size of the 2nd sorted array: ");
    if (scanf("%d", &size2) != 1 || size2 <= 0) return 1;

    int array2[size2];
    printf("Enter %d sorted elements for the second array:\n", size2);
    for (int i = 0; i < size2; i++) {
        printf("array2[%d]: ", i);
        scanf("%d", &array2[i]);
    }

    int mergedSize = size1 + size2;
    int merged[mergedSize];

    mergeSortedArrays(array1, size1, array2, size2, merged);

    printf("\nMerged Sorted Array with %d elements: ", mergedSize);
    for (int i = 0; i < mergedSize; i++)
    {
        printf("%d ", merged[i]);
    }
    printf("\n");

    return 0;
}
