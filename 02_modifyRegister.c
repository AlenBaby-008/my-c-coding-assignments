/* You are given an 8-bit register represented as an unsigned char. Write a function to:
● Set the 3rd bit (bit index 2).
● Clear the 6th bit (bit index 5).
● Toggle the 1st bit (bit index 0). Return the modified register value.
Note: Use bitwise operators only. Avoid loops or conditionals. */


#include<stdio.h>

unsigned char modifyRegister(unsigned char value){
    value  |= (1<<2);
    value &= ~(1<<5);
    value ^= (1<<0);
    return value;


}
int main(){
    unsigned char value;
    printf("Enter an unsigned char:");
    scanf("%hhu", &value);
    value = modifyRegister(value);

    printf("Modified register value: %hhu", value);
    
    return 0;



}



