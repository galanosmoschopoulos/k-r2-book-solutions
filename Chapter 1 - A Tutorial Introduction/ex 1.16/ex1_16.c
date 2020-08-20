#include <stdio.h>
#define MAXLINE 20

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;
    int max;
    int c, i;

    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0) {	
        if (len >= MAXLINE - 1 && line[len-1] != '\n') {
            for (i = len; (c=getchar()) != EOF && c != '\n'; ++i)
                ;	
                
            len = i;
        }
        else if(line[len-1] == '\n')
            len -= 1;
            
        printf("\t--> Word length = %d\n", len);

        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)
        printf("%s", longest);
    return 0;
}

int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
