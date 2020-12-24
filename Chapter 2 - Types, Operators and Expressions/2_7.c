#include <stdio.h>

int invert(int x, int p, int n);

int main() {
    int x, p, n;
    x = 157;
    p = 3;
    n = 3;
    x = invert(x, p, n);
    printf("%d\n", x);
    return 0;
}

int invert(int x, int p, int n)
{
    int mask;
    mask = ~(~0 << n) << p-n+1;
    return (x | mask) & ~(x & mask);
}