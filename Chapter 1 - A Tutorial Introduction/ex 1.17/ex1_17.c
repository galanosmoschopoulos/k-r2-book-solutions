#include <stdio.h>

#define MAXCHARS	1000
#define MAXLINES	100
#define THRESHOLD	80	

int get_line(char line[], int maxline);
void copy(char to[], char from[], int position, int fromLen);

int main()
{
	int len;
	char line[MAXCHARS];
	char linesPassed[(MAXCHARS+1)*MAXLINES + 1];						// We add ones to account for '\n' and '\0' 
	int copyPosition = 0;

	while ((len = get_line(line, MAXCHARS)) > 0)						// Repeat if there is another line, and not EOF
		if (len - 1 > THRESHOLD) {										// If the length is greater than the thresholf
			copy(linesPassed, line, copyPosition, len);					// Add the line to the array containing all the valid lines
			copyPosition += len;										// Update the new position in 'linesPassed', which will be the starting point for the next line copy
		}
	
	linesPassed[copyPosition] = '\0';									// Add '\0' to satisfy printf()
	printf("%s", linesPassed);

	return 0;
}

// Converts text input to char array, returns length (length includes '\n')
int get_line(char s[], int lim)
{
	int c, i;

	for (i = 0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)		// Copy user's text to the s array, stop when you meet '\n' or EOF (they indicate the end of the line)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;														// Add the newline character
		++i;	
	}
	
	return i;
}

// Copies an array to another array, starting from the last free position of the former array
void copy(char to[], char from[], int position, int fromLen)
{	
	int i;
	for (i = 0; i <= fromLen; ++i)										// Iterate through all indexes of the 'from' array
		to[i + position] = from[i];										// Start copying from the last free position in 'to'
}

		
