#include <stdio.h>

int setbits(int x, int p, int n, int y);

int main() {
    int x, p, n, y, xnew;
    x = 128;                        // 10000000
    p = 3;                          // 1000->0000
    n = 2;                          // 1000[00]00
    y = 199;                        // 110001[11]
    xnew = setbits(x, p, n, y);     // = 140 = 1000[11]00
    printf("%d\n", xnew);
    return 0;
}

int setbits(int x, int p, int n, int y)
{
    int d = p - n + 1;
    return x | ( ~(~0 << n) << d ) & ( (y | ~0 << n) << d | ~(~0 << d) );
}
