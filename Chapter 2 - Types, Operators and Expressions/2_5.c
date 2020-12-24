#include <stdio.h>

#define MAX_CHARS   1000

int get_line(char s[], int lim);
int any(char s1[], char s2[]);

int main() {
    char s1[MAX_CHARS];
    char s2[MAX_CHARS];

    printf("Enter s1:\n");
    get_line(s1, MAX_CHARS);
    printf("Enter s2:\n");
    get_line(s2, MAX_CHARS);

    printf("%d\n", any(s1, s2));
    return 0;
}

int any(char s1[], char s2[])
{
    int i, j, valFound;
    valFound = 0;
    for(i = 0; s1[i] != '\0' && valFound == 0; ++i)
        for(j = 0; s2[j] != '\0' && valFound == 0; ++j)
            if(s1[i] == s2[j] && s1[i] != '\n' && valFound == 0)
                ++valFound;
    if(!valFound)
        i = 0;
    return i-1;
}

get_line(char s[], int lim)
{
    int c, i;
    for(i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if(c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
