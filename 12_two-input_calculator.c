/*
Write a C program that uses functions to evaluate a simple arithmetic expression
given two numbers and an operator.
Description: The program should prompt the user to enter two floating-point
numbers and an arithmetic operator (+, -, *, /). A separate function must be written for
each operation (add, subtract, multiply, divide). A selector function should take the
operator as a parameter and call the appropriate function, returning the result to main.
Division by zero must be handled gracefully inside the divide function.
*/



#include <stdio.h>
#include <math.h>

double add(float a, float b)
{
    return a + b;
}

double subtract(float a, float b)
{
    return a - b;
}

double multiply(float a, float b)
{
    return a * b;
}

double divide(float a, float b)
{

    if (b == 0.0)
    {
        printf("Division by zero is not defined.");
        return NAN;
    }
    return a / b;
}


double calculate(float a, float b, char op)
{
    switch (op)
    {
        case '+':
            return add(a, b);
        case '-':
            return subtract(a, b);
        case '*':
            return multiply(a, b);
        case '/':
            return divide(a, b);
        default:
            printf("Invalid input.", op);
            return NAN;
    }
}

int main()
{
    float num1, num2;
    char opera;

    printf("Enter the first number: ");
    scanf("%f", &num1);


    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &opera);

    printf("Enter the second number: ");
    scanf("%f", &num2);


    double result = calculate(num1, num2, opera);


    if (!isnan(result))
    {
        printf("\nResult: %.4g %c %.4g = %.4g\n\n", num1, opera, num2, result);
    }

    return 0;
}
