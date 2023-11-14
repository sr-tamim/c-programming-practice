#include <stdio.h>

int main() {
    // declare variables
    int num1, num2, sum;
    
    printf("Enter the first number: ");
    scanf("%d", &num1); // get input from user
    
    printf("Enter the second number: ");
    scanf("%d", &num2); // get input from user
    
    sum = num1 + num2; // add the two numbers
    
    printf("The sum of %d and %d is %d\n", num1, num2, sum);
    
    return 0;
}
