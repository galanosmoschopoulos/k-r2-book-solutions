#include <stdio.h>

#define YES	1
#define NO	0

int main()
{
	int c, alreadyPrinted;              // alreadyPrinted is used to replace else

	while ((c = getchar()) != EOF) {    // Run as long as the user hasn't entered EOF
		alreadyPrinted = NO;
		if (c == '\t') {                // If a blank, a tab, a backspace or a backslash is detected, print C's representation special character 
			putchar('\\');
			putchar('t');
			alreadyPrinted = YES;
		}
		if (c == '\b') {
			putchar('\\');
			putchar('b');
			alreadyPrinted = YES;
		}
		if (c == '\\') {
			putchar('\\');
			putchar('\\');
			alreadyPrinted = YES;
		}
		if (alreadyPrinted == NO)       // If no special character was detected, print the char
			putchar(c);
	}
}

