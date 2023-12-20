#include<stdio.h>

void fibonacci(int, double, double);

int main()
{
    int limit;
    printf("Length of Fibonacci series = ");
    scanf("%d", &limit);
    fibonacci(limit, 0, 0);

    return 0;
}

void fibonacci(int limit, double prev, double curr)
{
    printf("%.0lf, ", curr);
    double next = prev + curr;
    if (limit > 0)
        fibonacci(--limit, curr, (next == 0) ? 1 : next);
}
