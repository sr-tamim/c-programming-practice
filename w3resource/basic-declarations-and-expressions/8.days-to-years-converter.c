/*
    8. Write a C program to convert specified days into years, weeks and days. (Ignore leap year)
*/

#include<stdio.h>

main()
{
    int days, weeks, years, remainingDays;
    printf("Days converter\n\nHow many days?\n");
    scanf("%d", &days);

    years = days / 365;
    weeks = (days - years * 365) / 7;
    remainingDays = days - (years * 365) - (weeks * 7);

    printf("Years: %d \nWeeks: %d \nDays: %d", years, weeks, remainingDays);
}
