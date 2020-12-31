#include <stdio.h>

#define MAXLINES	100
#define MAXCHARS	1000
#define MAXTABS		100

int tabStop = 8;	// For GNU/Linux terminal emulator

int getLine(char line[], int maxline);
int processLine(char line[], int length, char converted[]);
void copy(char to[], char from[], int position, int fromLen);

int main()
{
    int len, copyPosition, newLen;
    extern int tabStop;

    char currentLine[MAXCHARS + 1];
    char convertedLine[MAXCHARS + 1 + MAXTABS * tabStop];
    char allLines[MAXLINES*(MAXCHARS + 1 +  MAXTABS * tabStop)];

    copyPosition = 0;

    while ((len = getLine(currentLine, MAXCHARS)) > 0) {

        newLen = processLine(currentLine, len, convertedLine);
        copy(allLines, convertedLine, copyPosition, newLen);
        copyPosition += newLen;
    }

    if (copyPosition > 0) {
        allLines[copyPosition] == '\0';
        printf("%s", allLines);
    }

    return 0;
}

int processLine(char line[], int length, char convertedLine[])
{
    extern int tabStop;
    int i, j, writingPos;
    writingPos = 0;
    for (i = 0; i < length; ++i) {
        if(line[i] == '\t') {
            for(j = 0; j < tabStop - (writingPos%tabStop); ++j)
                convertedLine[writingPos + j] = ' ';
            writingPos += --j;
        }
        else
            convertedLine[writingPos] = line[i];
        ++writingPos;
    }

    return writingPos;
}

int getLine(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c=getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    return i;
}

void copy(char to[], char from[], int position, int fromLen) {
    int i;
    for (i = 0; i < fromLen; ++i)
        to[i + position] = from[i];
}