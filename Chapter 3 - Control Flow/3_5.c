#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
    int x, b;
    char string[10];
    x = -2147483648, b = 16;
    itob(x, string, b);
    printf("%s\n", string);
    return 0;
}

void itob(int n, char s[], int b)
{
    int i, sign, digit;
    sign = n>0?0:-1;
    i = 0;
    do {
        digit = n>0?(n%b):-(n%b);
        s[i++] = (digit <= 9)?(digit + '0'):(digit - 10 + 'A');
    } while ((n /= b) != 0);
    switch(b) {
        case 2:
            s[i++] = 'b', s[i++] = '0';
            break;
        case 8:
            s[i++] = 'o', s[i++] = '0';
            break;
        case 16:
            s[i++] = 'x', s[i++] = '0';
            break;
        default:
            break;
    }
    if (sign < 0)
        s[i++] = '-';
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