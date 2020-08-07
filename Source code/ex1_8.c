#include <stdio.h>

main()
{
	int c, nSpace, nTab, nNewLine;
	nSpace = nTab = nNewLine = 0;

	while((c = getchar()) != EOF) {
		if (c == ' ')
			++nSpace;
		if (c == '\t')
			++nTab;
		if (c == '\n')
			++nNewLine;
	}

	printf("\nNumber of spaces: %d\nNumber of tabs: %d\nNumber of newlines: %d\n", nSpace, nTab, nNewLine);
}
