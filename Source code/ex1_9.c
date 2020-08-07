#include <stdio.h>

#define YES	1
#define NO	0

main()
{
	int c, spaceOccured;
	spaceOccured = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			if (spaceOccured == NO)
				putchar(c);
			spaceOccured = YES;
		}
				
		if (c != ' ') {
			putchar(c);
			spaceOccured = NO;
		}
	}
}
