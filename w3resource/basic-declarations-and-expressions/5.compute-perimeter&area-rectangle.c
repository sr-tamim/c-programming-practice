/*
    5. Write a C program to compute the perimeter and area of a rectangle and take height and width as input.
*/

#include<stdio.h>

main()
{
    int height, width, perimeter, area;
    printf("Type the height of the rectangle: ");
    scanf("%d", &height);

    printf("Type the width of the rectangle: ");
    scanf("%d", &width);
    perimeter = (height + width) * 2;
    area = height * width;

    printf("\nPerimeter of the rectangle is = %d", perimeter);
    printf("\nArea of the rectangle is = %d\n", area);
}
