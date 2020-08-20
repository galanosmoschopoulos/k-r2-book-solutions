#include <stdio.h>

int main()
{
	// Declaring and initializing variables
	int c, nSpace, nTab, nNewLine;
	nSpace = nTab = nNewLine = 0;

	while((c = getchar()) != EOF) {     // Execute unless the user enters EOF
		if (c == ' ')                   // If the user enters a blank, a tab or a newline, increase the according variable by one
			++nSpace;
		if (c == '\t')
			++nTab;
		if (c == '\n')
			++nNewLine;
	}

	// Print the value of the variables
	printf("\nNumber of spaces: %d\nNumber of tabs: %d\nNumber of newlines: %d\n", nSpace, nTab, nNewLine);
}
