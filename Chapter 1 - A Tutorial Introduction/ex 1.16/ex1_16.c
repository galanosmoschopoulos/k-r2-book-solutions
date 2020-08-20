#include <stdio.h>
#define MAXLINE 10                                                  // We define the max number of chars including '\n' and '\0'

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
    int len;
    int max;
    int c;

    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0) {                   // While there is a next line (whose length is obviously > 0)
        if (len >= MAXLINE - 1 && line[len-1] != '\n') {            // If its length detected by get_line is the maximum possible with respect to MAXLINE, and its last char isn't a newline
            for ( ; (c=getchar()) != EOF && c != '\n'; ++len)       // Add one to detected length until you meet EOF or newline
                ;	
        }
        else if(line[len-1] == '\n')                                // If its last char is newline.. (that means that its length is inside the limits if MAXLINE even if its length = MAXLINE-1)
            len -= 1;                                               // Correct the length from get_line so that '\n' isn't taken into consideration
            
        printf("\t--> Word length = %d\n", len);

        if (len > max) {                                            // If the line is the largest so far, copy it to 'longest' and update 'max'
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

    for (i = 0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)  // Save user input to 's[]' until you find EOF or newline, or you reach the limit MAXLINE
        s[i] = c;
    if (c == '\n') {                                                // Add newline, if the user has entered it
        s[i] = c;
        ++i;
    }
    s[i] = '\0';                                                    // Add '\0' to make it a valid string
    return i;                                                       // Return length, including '\n'
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')                               // Assign the value of the Ith element of to[] to the Ith element of from[] until you meet '\0'
        ++i;
}
