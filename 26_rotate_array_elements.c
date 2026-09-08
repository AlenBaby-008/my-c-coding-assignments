/*
Write a C program that rotates the elements of an array by n positions in a
specified direction.
Description: The program should prompt the user to enter the array elements, the
number of positions (n) to rotate, and the direction (left or right). It must then shift the
elements accordingly — elements that fall off one end should reappear at the opposite
end. The rotation must work for any value of n, including values larger than the array
size. The final rotated array should be displayed on the screen.
*/



#include <stdio.h>
#include <ctype.h>

void reverse(int array[], int start, int end) {
    while (start < end)
    {
        int temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }
}

void rotateArray(int array[], int size, int rotaCount, char direction)
{

    rotaCount = rotaCount % size;
    if (rotaCount == 0)
    {
        return;
    }

    direction = (char)toupper((unsigned char)direction);

    if (direction == 'L')
    {
        reverse(array, 0, rotaCount - 1);
        reverse(array, rotaCount, size - 1);
        reverse(array, 0, size - 1);
    }
    else if (direction == 'R')
    {
        reverse(array, 0, size - 1);
        reverse(array, 0, rotaCount - 1);
        reverse(array, rotaCount, size - 1);
    }
}

int main()
{
    int size, rotaCount;
    char direction;

    printf("Enter the size of the array: ");
    if (scanf("%d", &size) != 1 || size <= 0) return 1;


    int array[size];

    printf("Enter %d element(s):\n", size);
    for (int i = 0; i < size; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("Enter number of positions to rotate: ");
    if (scanf("%d", &rotaCount) != 1 || rotaCount < 0) return 1;

    printf("Enter rotation direction ('L' for Left, 'R' for Right): ");
    scanf(" %c", &direction);
    if (toupper((unsigned char)direction) != 'L' && toupper((unsigned char)direction) != 'R')
    {
        printf("Direction invalid. Enter 'L' or 'R'.\n");
        return 1;
    }

    printf("\nOriginal Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    rotateArray(array, size, rotaCount, direction);

    printf("Array is rotated %s by %d position(s)): ", toupper((unsigned char)direction) == 'L' ? "Left" : "Right", rotaCount);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
