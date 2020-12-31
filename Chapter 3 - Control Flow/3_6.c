#include <stdio.h>
#include <string.h>

void itoa(int n, char s[], int w);
void reverse(char s[]);

int main()
{
    int x, w;
    char string[10];
    x = -258;
    w = 10;
    itoa(x, string, w);
    printf("%s\n", string);
    return 0;
}

void itoa(int n, char s[], int w)
{
    int i, sign;
    sign = n>0?0:-1;
    i = 0;
    do {
        s[i++] = (n>0?(n%10):-(n%10)) + '0';
    } while ((n /= 10) != 0);
    if (sign < 0)
        s[i++] = '-';
    while(i < w)
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}