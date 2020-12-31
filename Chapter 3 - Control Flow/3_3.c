#include <stdio.h>
#include <ctype.h>

#define MAX_CHARS 100

int get_line(char s[], int lim);
void expand(char s1[], char s2[]);

int main()
{
    char line[MAX_CHARS];
    char processed[MAX_CHARS];

    get_line(line, MAX_CHARS);
    expand(line, processed);

    printf("%s\n", processed);

    return 0;

}

void expand(char s1[], char s2[])
{
    unsigned int i, j;
    unsigned char first, last, d;
    signed char step;
    for (i=j=d=0; s1[i] != '\0'; ++i) {
        first = s1[i], last = s1[i+2];
        if (s1[i + 1] == '-' && (isupper(first) && isupper(last) || islower(first) &&
            islower(last) || isdigit(first) && isdigit(last))) {
            step = (first < last)? 1 : -1;
            for (s2[j++] = first; s2[j - 1] != last; s2[j++] = s2[j - 1] + step);
            d = 1, ++i;
        }
        else if (d == 0)
            s2[j++] = s1[i];
        else
            d = 0;
    }
    s2[j] = '\0';
}

int get_line(char s[], int lim)
{
    int c, i;

    for (i=0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}