#include <stdio.h>

#define MAXCHARS	1000
#define MAXLINES	100
#define TRUE		1
#define FALSE		0

int getLine(char line[], int maxLine);
int processLine(char line[], int length);
void copy(char to[], char from[], int position, int fromLen);

int main()
{
    int len, newLen, copyPosition;

    char currentLine[MAXCHARS];
    char allLines[(MAXCHARS + 1) * MAXLINES + 1];							// We add ones to account for '\n' and '\0' 

    copyPosition = 0;

    while ((len = getLine(currentLine, MAXCHARS)) > 0) {					// Repeat if there is another line (and not EOF)
        if ((newLen = processLine(currentLine, len)) != 0) {				// Proceed if the line is not blank
            copy(allLines, currentLine, copyPosition, newLen);				// Copy the processed line to the 'allLines' array
            copyPosition += newLen;                                         // Update the new position in 'allLines', which will be the starting point for the next line copy
        }
    }
    if (copyPosition > 0) {                                                 // If any lines were copied
        allLines[copyPosition] == '\0';                                     // Add '\0' to satisfy printf()
        printf("%s", allLines);
    }

    return 0;
}

// Copies an array to another array, starting from the last free position of the former array
void copy(char to[], char from[], int position, int fromLen)
{
    int i;
    for (i = 0; i < fromLen; ++i)											// Iterate through all indexes of the 'from' array
        to[i+position] = from[i];											// Start copying from the last free position in 'to'
}

// Converts text input to char array, returns length (length includes '\n')
int getLine(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i) {	// Copy user's text to the s array, stop when you meet '\n' or EOF (they indicate the end of the line)
        s[i] = c;
    }
    if (c == '\n') {														// Add the newline character
        s[i] = c;
        ++i;
    }
    
    return i;
}

// Detects and removes discards trailing blanks/tabs and empty lines
int processLine(char s[], int len)
{
    int emptyLine, endPoint, i, foundPoint;
    emptyLine = TRUE;
    foundPoint = FALSE;
    
    
    for (i = 0; i <= len - 1; ++i)											// If any character except space, tab or newline is found, the line is not empty
        if (s[i] != '\n' && s[i] != '\t' && s[i] != ' ')
            emptyLine = FALSE;

    if (emptyLine == FALSE) {
        if (s[len - 2] == ' ' || s[len - 2] == '\t') {						// If there is a space/tab in the end of the line
            for (i = len - 2; i >= 0; --i) {								// Iterate backwards through the array
                if (s[i] != ' ' && s[i] != '\t') {							// If you find an element that isn't space nor tab
                    if (foundPoint == FALSE) {								// Store the position of the last non-space character
                        endPoint = i;
                        foundPoint = TRUE;
                    }
                }
            }
            s[endPoint+1] = '\n';											// Add a newline after the last character
            len = endPoint+2;												// Compute the length of the processed line
            // Note: we don't need to erase the trailing blanks and tabs as the new length will tell the other functions when to stop iterating through the array
        }
    }	

    else {
        len = 0;															// If the line is empty, its length is set to 0
    }

    return len;
}

        




