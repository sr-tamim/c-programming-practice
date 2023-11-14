
#include <stdio.h>

int main(void)
{
    int n1, n2, n3;
    float average;

    printf("Enter three integers: ");
    scanf("%d%d%d", &n1, &n2, &n3);

    average = (n1 + n2 + n3) / 3.0f;

    printf("Average: %.2f\n", average);

    return 0;
}