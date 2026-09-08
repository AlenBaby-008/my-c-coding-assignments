/*
Write a C program that finds all pairs of elements in an array whose sum equals
a given target value.
Description: The program should prompt the user to enter the size of the array, its
elements, and a target sum. It must then examine all possible pairs of elements in the
array and identify every pair whose sum matches the target. Each valid pair should be
printed on the screen. If no such pair exists, an appropriate message should be
displayed. The same element should not be paired with itself.
*/



#include <stdio.h>


int targetSumPairs(const int arr[], int n, int targSum)
{
    int pairCount = 0;

    printf("\nSum of Pairs that gives %d:\n", targSum);

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == targSum)
            {
                pairCount++;
                printf("Pair %d: (%d, %d) [Indices: %d, %d]\n", pairCount, arr[i], arr[j], i, j);
            }
        }
    }

    return pairCount;
}

int main()
{
    int size, targetSum;

    printf("Enter the size of the array: ");
    if (scanf("%d", &size) != 1 || size < 2) return 1;

    int array[size];

    printf("Enter %d element(s):\n", size);
    for (int i = 0; i < size; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    printf("\nArray: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    int count = targetSumPairs(array, size, targetSum);

    if (count == 0)
    {
        printf("None of the pairs gives %d.\n", targetSum);
    }
    else
    {
        printf("Total pairs: %d\n", count);
    }

    return 0;
}
