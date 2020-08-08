#include <stdio.h>

#define YES	1
#define NO	0

main()
{
	int c, alreadyPrinted;

	while ((c = getchar()) != EOF) {
		alreadyPrinted = NO;
		if (c == '\t') {
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
		if (alreadyPrinted == NO)
			putchar(c);
	}
}

