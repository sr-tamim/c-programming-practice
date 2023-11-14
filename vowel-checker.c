#include <stdio.h>

int main() {
    char c; // declare variable
    printf("Enter a character: ");
    scanf("%c", &c); // get input from user

    // check if c is a vowel
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        printf("%c is a vowel.\n", c); // print vowel if true
    } else {
        printf("%c is a consonant.\n", c); // print consonant if false
    }

    return 0;
}
