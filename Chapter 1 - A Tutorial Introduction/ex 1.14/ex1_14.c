#include <stdio.h>

#define CHAR_NUMBER	128                                             // To handle all 128 ASCII values

int main()
{
    int c, i, j;
    int charFrequency[CHAR_NUMBER];                                 // Each index n of the array 'charFrequency' contains the frequency of the char with ASCII value = n

    for (i = 0; i < CHAR_NUMBER; ++i)                               // Initialize array with zeros
        charFrequency[i] = 0;

    while ((c = getchar()) != EOF)                                  // Read user input until you find EOF
        ++charFrequency[c-0];                                       // The frequency of a char c is encreased by one

    printf("\n\nCharacter | Frequency\n----------|----------\n");
    for (i = 0; i < CHAR_NUMBER; ++i) {
        if (charFrequency[i] > 0) {                                 // There's no point in printing characters that have never been entered by the user
            if (i < 33)
                printf("%#9x", i);                                  // If the ASCII value is < 33, print the ASCII value in HEX because the char itself is not visible (i.e. blank, tab, newline, etc.)
            else
                printf("%9c", i);                                   // The rest pf the characters are normal (i.e. 'A', '|', '!', etc.), so we can print them just fine
            
            printf(" | (%3d) ", charFrequency[i-0]);
            for (j = 0; j < charFrequency[i-0]; ++j)                // Place the '#' as many times as a char c has been entered by the user
                putchar('#');
            putchar('\n');
        }
    }
}
