#include <stdio.h>

#define MAXCHARS 100

int get_line(char line[], int maxline);
int h_toi(char line[]);

int main()
{
	int val;
	char line[MAXCHARS];

	get_line(line, MAXCHARS);
	val = h_toi(line);
	printf("%#x, %d\n", val, val);
}

int h_toi(char s[])
{
	int i, n, c;
	n = 0;
	for (i = 0; ((c = s[i]) >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F') || c == 'x' || c == 'X'; ++i) {
		if (c >= 'A' && c <= 'F')
			n = 0x10 * n + (c - 'A' + 0xA);
		else if (c >= '0' && c <= '9')
			n = 0x10 * n + (c - '0');
		else if (c >= 'a' && c <= 'f')
			n = 0x10 * n + (c - 'a' + 0xA);
	}
	return n;
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
