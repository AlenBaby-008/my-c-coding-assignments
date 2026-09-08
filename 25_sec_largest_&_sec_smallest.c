/*
Write a C program that uses an array to find the second largest and second
smallest element in a list of numbers.
Description: The program should prompt the user to enter the size of the array and its
elements. It must then scan through the array and determine both the second largest
and second smallest values without sorting the array. The program should handle
duplicate values correctly — if all elements are the same, it should display an
appropriate message. Both results should be displayed on the screen.
*/



#include <stdio.h>
#include <limits.h>
#include <stdbool.h>


bool secLargestSmallest(const int arr[], int n, int *secondSmallest, int *secondLargest)
{

    int smallest = INT_MAX, secSmallest = INT_MAX;
    int largest = INT_MIN, secLargest = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int current = arr[i];
        if (current < smallest)
        {
            secSmallest = smallest;
            smallest = current;
        }
        else if (current > smallest && current < secSmallest)
        {
            secSmallest = current;
        }

        if (current > largest)
        {
            secLargest = largest;
            largest = current;
        }
        else if (current < largest && current > secLargest)
        {
            secLargest = current;
        }
    }


    if (secSmallest == INT_MAX || secLargest == INT_MIN)
    {
        return false;
    }

    *secondSmallest = secSmallest;
    *secondLargest = secLargest;
    return true;
}

int main()
{
    int size;

    printf("Enter the size of the array: ");
    if (scanf("%d", &size) != 1 || size < 2) return 1;

    int array[size];

    printf("Enter %d element(s):\n", size);
    for (int i = 0; i < size; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    int secSmallest, secLargest;


    if (secLargestSmallest(array, size, &secSmallest, &secLargest))
    {
        printf("\n2nd Smallest Element: %d\n", secSmallest);
        printf("2nd Largest Element:  %d\n", secLargest);
    }
    else

    {
        printf("\nCould not find distinct 2nd smallest or largest because all elements in the array may be identical or insufficient distinct values exist.\n");
    }

    return 0;
}
