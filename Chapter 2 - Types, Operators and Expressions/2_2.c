#include <stdio.h>
#define MAXLINE 10

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

main()
{
	int len;
	int max;

	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = get_line(line, MAXLINE)) > 0)	
		if (len > max) {
			max = len;	
			copy(longest, line);
		}
	if (max > 0)
		printf("%s", longest);
	return 0;
}

int get_line(char s[], int lim)
{
	int c, i;
	
	/* An logical expression that evaluates to true has a numerical value of 1. Thus, if the expressions a, b, c are all true, (a) + (b) + (c) = 1 + 1 + 1 = 3 */ 
	for (i = 0; (i<lim-1) + ((c=getchar()) != EOF) + (c != '\n') == 3; ++i) {
		s[i] = c;
	}
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
