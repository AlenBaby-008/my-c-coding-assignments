/* 1. Write a function in C that takes an array of integers and its size, and returns the
second largest element.
Constraints:
● Do not sort the array.
● Assume the array has at least two distinct elements. */




#include<stdio.h>
int secondLargest(int array[], int size){

    for (int i = 0; i<size; i++){
        printf("%d\n", array[i]);
    }
    printf("\n");

    int largest, secondLargest;
    if (array[0]> array[1]){
            largest = array[0];
            secondLargest = array[1];

    }

    else{
            largest = array[1];
            secondLargest = array[0];

    }



    for (int i = 2; i<size; i++){
        if (largest < array[i]){

                secondLargest = largest;
                largest = array[i];



        }
        else if (array[i] < largest && secondLargest < array[i] ){

                secondLargest = array[i];


        }



    }
     return secondLargest;

}

int main(){

    int array[100], size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    for (int i = 0; i<size; i++){
        scanf("%d", &array[i]);
    }

    int result = secondLargest(array, size);
    printf("The Second Largest is %d", result);

  return 0;


}
