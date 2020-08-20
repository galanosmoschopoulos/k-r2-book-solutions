#include <stdio.h>

#define YES	1
#define NO	0

int main()
{
	int c, spaceOccured;
	spaceOccured = 0;

	while ((c = getchar()) != EOF) {    // Run unless user inputs EOF
		if (c == ' ') {                 // If a blank is detected
			if (spaceOccured == NO)     // If there was no blank before this blank
				putchar(c);             // Print the blank
			spaceOccured = YES;         // Save the fact that a blank just ocured
		}
				
		if (c != ' ') {                 // If the char isn't blank
			putchar(c);                 // Print the char
			spaceOccured = NO;          // Save the fact that the last char wasn't a blank
		}
	}
}
