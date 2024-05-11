#include<stdio.h>

void fibonacci(int, double, double);

int fibo(int n)
{
    return n <= 1 ? n : fibo(n - 1) + fibo(n - 2);
}

int main()
{
    int limit;
    printf("Length of Fibonacci series = ");
    scanf("%d", &limit);
    //fibonacci(limit, 0, 0);

    for (int i = 0; i < limit; i++)
    {
        printf("%d,", fibo(i));
    }

    return 0;
}

void fibonacci(int limit, double prev, double curr)
{
    printf("%.0lf, ", curr);
    double next = prev + curr;
    if (limit > 0)
        fibonacci(--limit, curr, (next == 0) ? 1 : next);
}
