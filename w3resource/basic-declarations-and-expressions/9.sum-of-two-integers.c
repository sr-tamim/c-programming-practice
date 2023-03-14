/*
    Write a C program that accepts two integers from the user and calculates the sum of the two integers.
*/

#include <stdio.h>

main()
{
    int a, b, sum;
    printf("Input first number: ");
    scanf("%d", &a);
    printf("Input second number: ");
    scanf("%d", &b);

    sum = a + b;
    printf("\nThe sum of the above two numbers is %d\n", sum);
}
