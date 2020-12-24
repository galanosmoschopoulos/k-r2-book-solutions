#include <stdio.h>

#define MAX_CHARS   1000

int get_line(char s[], int lim);
void squeeze_alt(char s1[], char s2[]);

int main() {
    char s1[MAX_CHARS];
    char s2[MAX_CHARS];

    printf("Enter s1:\n");
    get_line(s1, MAX_CHARS);
    printf("Enter s2:\n");
    get_line(s2, MAX_CHARS);

    squeeze_alt(s1, s2);

    printf("%s\n", s1);
    return 0;
}

void squeeze_alt(char s1[], char s2[])
{
    int i, j, k, inS2;

    for(i = j = 0; s1[i] != '\0'; i++) {
        inS2 = 0;
        for(k = 0; s2[k] != '\0'; k++) {
            if(s2[k] == s1[i])
                ++inS2;
        }
        if(inS2 == 0) {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
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
