/*
Define a structure Complex with real and imaginary parts. Write a C program to add
two complex numbers and display the result.
Description: The program should define a structure to represent a complex number
with two members: real part and imaginary part. It must then create functions to
perform addition of two complex numbers and to display a complex number in a
readable format (e.g., a + bi). The program should take input for two complex
numbers, compute their sum using the defined function, and print the result.
*/




#include <stdio.h>

typedef struct
{
    double real;
    double imag;
} Complex;

Complex addComplex(Complex c1, Complex c2)
{
    Complex sum;
    sum.real = c1.real + c2.real;
    sum.imag = c1.imag + c2.imag;
    return sum;
}

void printComplex(Complex c)
{

    printf("%.2f + %.2fi\n", c.real, c.imag);
}

int main()
{
    Complex c1, c2;

    printf("Enter real and imaginary parts of 1st complex number: ");
    if (scanf("%lf %lf", &c1.real, &c1.imag) != 2) return 1;

    printf("Enter real and imaginary parts of 2nd complex number: ");
    if (scanf("%lf %lf", &c2.real, &c2.imag) != 2) return 1;

    Complex sum = addComplex(c1, c2);

    printf("\n1st Complex Number:  ");
    printComplex(c1);

    printf("2nd Complex Number: ");
    printComplex(c2);

    printf("-----------------------------------\n");
    printf("Sum:                   ");
    printComplex(sum);

    return 0;
}
