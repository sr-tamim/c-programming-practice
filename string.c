#include <stdio.h>
#include <string.h>

int main() {
    // String Initialization
    char str1[20] = "Hello, ";
    char str2[20] = "World!";
    char str3[40];
    char str4[50];

    // get string input and keep it in str3
    printf("Enter a string: ");
    scanf("%s", str4);

    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);
    printf("String 4: %s\n", str4);

    // String Concatenation
    strcat(str1, str2);
    printf("String Concatenation: %s\n", str1);

    // String Copy
    strcpy(str3, str1);
    printf("String Copy: %s\n", str3);

    // String Length
    printf("String Length: %ld\n", strlen(str4));

    // String Comparison
    printf("String Comparison: %d\n", strcmp(str1, str3));

    for (int i = 0; i < strlen(str4); i++) {
        printf("%c\n", str4[i]);
    }

    return 0;
}