#include <stdio.h>
#include <string.h>

void itoa(int n, char s[]);
void reverse(char s[]);

int main()
{
    int x;
    char string[10];
    x = -2147483648;
    itoa(x, string);
    printf("%s\n", string);
    return 0;
}

void itoa(int n, char s[])
{
    int i, sign;
    /* The given version had the n = -n statement. In a two's complement system, the max value = 2^(word length - 1) - 1
       and the min value is -2^(word length - 1). However -(-2^(word length - 1)) = 2^(word length - 1) > max value.
       Thus we have integer overflow and get a wrong result. */
    sign = n>0?0:-1;
    i = 0;
    do {
        s[i++] = (n>0?(n%10):-(n%10)) + '0'; // We fix this problem by converting the module result to positive each time
    } while ((n /= 10) != 0);
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