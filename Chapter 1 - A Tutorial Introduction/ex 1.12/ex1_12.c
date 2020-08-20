#include <stdio.h>

#define IN	1
#define OUT	0

int main()
{
	int c, state;
	state = OUT;                                    // Expresses whether we're iterating through a word or not
	while((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {   // If a black, a tab or a newline is detected (they usually separate words)
			if (state == IN)                        // and if we just finished iterating through a word
				putchar('\n');                      // Leave a line
			state = OUT;                            // We're now out of the world
		}
		else {
			state = IN;                             // If we're iterating through a world, print its characters normally
			putchar(c);
		}
	}
}

