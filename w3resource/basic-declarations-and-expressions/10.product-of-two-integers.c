/*
    10. Write a C program that accepts two integers from the user and calculates the product of the two integers.
*/

#include <stdio.h>

int main()
{
    int a, b, product;
    printf("Input first integer: ");
    scanf("%d", &a);
    printf("Input second integer: ");
    scanf("%d", &b);

    product = a * b;
    printf("\nProduct of the above two integers = %d\n", product);
}
