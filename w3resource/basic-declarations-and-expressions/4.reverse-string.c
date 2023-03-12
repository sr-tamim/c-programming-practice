/*
4. Write a C program to print the following characters in a reverse way.
*/
#include<string.h>
#include<stdio.h>

main()
{
    char input_str[] = "XML";
    printf("The reverse of %s is %c%c%c", input_str, input_str[2], input_str[1], input_str[0]);
}
