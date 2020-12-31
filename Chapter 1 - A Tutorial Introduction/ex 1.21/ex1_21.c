#include <stdio.h>

#define MAXLINES	100
#define MAXCHARS	1000
#define MAXTABS	100

int tabStop = 8;

int getLine (char line[], int maxline);
int entab   (char line[], int length, char convertedLine[]);
int detab   (char line[], int length, char convertedLine[]);
void copy   (char to[], char from[], int position, int fromLen);

int main()
{
    int len, newLen, copyPosition;

    char currentLine    [MAXCHARS + 1];
    char convertedLineA [MAXCHARS + 1 + MAXTABS * tabStop];
    char convertedLineB [MAXCHARS + 1];
    char allLines       [MAXLINES * (MAXCHARS + 1) + 1];

    copyPosition = 0;

    while ((len = getLine(currentLine, MAXCHARS)) > 0) {
        newLen = detab(currentLine, len, convertedLineA);
        newLen = entab(convertedLineA, newLen, convertedLineB);
        copy(allLines, convertedLineB, copyPosition, newLen);
        copyPosition += newLen;
    }

    if (copyPosition > 0) {
        allLines[copyPosition] == '\0';
        printf("%s", allLines);
    }

    return 0;

}

int detab(char line[], int length, char convertedLine[])
{
    extern int tabStop;
    int i, j, writingPos;
    writingPos = 0;

    for (i = 0; i < length; ++i) {
        if (line[i] == '\t') {
            for (j = 0; j < tabStop - (writingPos%tabStop); ++j)
                convertedLine[writingPos + j] = ' ';
            writingPos += --j;
        }
        else
            convertedLine[writingPos] = line[i];
        ++writingPos;
    }

    return writingPos;
}

int entab(char s[], int len, char convertedLine[])
{
    extern int tabStop;
    int i, j, blankA, blankB, writingPos;
    blankA = blankB = 0;
    writingPos = 0;

    for (i = 0; i < len; ++i) {
        if (s[i] == ' ' && i > blankB) {
            blankA = i;
            for (j = i; j < len; ++j)
                if (s[j+1] != ' ') {
                    blankB = j;
                    j = len;
                }
            for (j = blankA; j <= blankB; ) {
                if ((j + tabStop - j%tabStop - 1) <= blankB) {
                    convertedLine[writingPos] = '\t';
                    j += tabStop - j%tabStop;
                }
                else {
                    convertedLine[writingPos] = ' ';
                    ++j;
                }
                ++writingPos;
            }
        }

        else if(s[i] != ' ') {
            convertedLine[writingPos] = s[i];
            ++writingPos;
        }
    }

    return writingPos;
}

int getLine(char s[], int lim)
{
    int c, i;

    for (i = 0; i <lim-1 && (c=getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    return i;
}

void copy(char to[], char from[], int position, int fromLen)
{
    int i;

    for (i = 0; i < fromLen; ++i)
        to[i + position] = from[i];
}