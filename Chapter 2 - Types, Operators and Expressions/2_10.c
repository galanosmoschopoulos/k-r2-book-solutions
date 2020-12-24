#include <stdio.h>

int lower(int c);

int main() {
    char upper = 'D';
    printf("%c\n", lower(upper));
    return 0;
}

int lower(int c)
{
    return (c >= 'A' && c <= 'Z')?(c + 'a'-'A'):c;
}