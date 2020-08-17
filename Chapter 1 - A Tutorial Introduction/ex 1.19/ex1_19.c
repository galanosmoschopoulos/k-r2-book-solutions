#include <stdio.h>

#define MAXCHARS 1000

void reverse(char s[], int len);
int getLine(char s[], int lim);

int main()
{
	int len;
	char line[MAXCHARS];

	while((len = getLine(line, MAXCHARS)) > 0) {	// Run if there is another line to process
		reverse(line, len);			// Call the reverse function
		if (line[len-1] == '\n')		// If the line ends in '\n', just add '\0', to satisfy printf()
			line[len] = '\0';
		else {
			line[len] = '\n';		// Else, add both '\n' and '\0', to make output prettier
			line[len+1] = '\0';
			putchar('\n');
		}
		printf("%s", line);
	}

	return 0;

}

void reverse(char s[], int len)				// Length takes into account the '\n' character (eg. line = hi(\n), len = 3)
{
	int maxIndex, midPoint, i, tempValue;
	
	if (s[len-1] == '\n')				// We don't want to take into account '\n', as it shouldn't be reversed, so we check if it exists and set our max character index accordingly
		maxIndex = len - 2;
	else
		maxIndex = len - 1;

	midPoint = maxIndex / 2;			// The middle of the char part of the array

	if (maxIndex >= 1)				// If the array consists of less than 2 chars, they can't be reversed
		for (i = 0; i <= midPoint; ++i) {
			tempValue = s[i];		// Assign the value of element to-be-swapped to a temp variable
			s[i] = s[maxIndex - i];		// Give it the value of the opposite element
			s[maxIndex - i] = tempValue;	// Assign the temp value to the opposite element 
		}
}

int getLine(char s[], int lim)
{
	int c, i;

	// Copy user's text to the line array, stop when you meet '\n' or EOF (they indicate the end of the line)
	for (i = 0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; ++i) 
		s[i] = c;
	if (c == '\n') {
		s[i] = c;				// Add the newline character
		++i;
	}

	return i;
}
