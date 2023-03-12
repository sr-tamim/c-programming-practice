/*
    6. Write a C program to compute the perimeter and area of a circle with a given radius.
*/
#include<stdio.h>

#define PI 3.1416

main()
{
    float radius, perimeter, area;

    printf("Type the radius of the circle: ");
    scanf("%f", &radius);

    perimeter = 2 * PI * radius;
    area = PI * radius * radius;

    printf("\nPerimeter of the circle is = %f", perimeter);
    printf("\nArea of the circle is = %f\n", area);
}
