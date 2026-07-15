/* 3. Write a C program to print a pyramid of stars for a given number n.
If n = 5, the output should be:
    *
   ***
  *****
 *******
*********  */



#include<stdio.h>


 int main(){

int row;
printf("Enter the no of rows: ");
scanf("%d", &row);
for(int i=1; i<=row; i++){

    for (int k=0; k<row-i; k++){ 
        printf(" ");
    }
    for (int j=1; j<=2*i-1; j++){
        printf("*");
    }
    printf("\n");
    
   

 }
 return 0;
}
