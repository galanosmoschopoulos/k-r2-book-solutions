#include <stdio.h>

int rightrot(int x, int n);
int rightrotAlt(int x, int n);

int main() {
    printf("%d\n", rightrot(145456, 1000));
    printf("%d\n", rightrotAlt(145456, 1000));
    return 0;
}

int rightrot(int x, int n)                      // Works by rotating one bit at a time
{
    int i, xc = x;
    for(i=1; (xc>>=1) != 0; ++i);               // Counts the bits of x in i
    n %= i;                                     // To avoid the useless full rotations
    for( ; n > 0; --n)                          // Run the loop n times to rotate by 1 n times
        x = (x>>1) | (x & 1) << i-1;
    return x;
}

int rightrotAlt(int x, int n)                   // Works by simultaneously moving n bits from the right to the left
{
    int i, xc = x;
    for (i = 1; (xc >>= 1) != 0; ++i);
    n %= i;
    return x >> n | (x & ~(~0 << n)) << i - n;  // 'x & ~(~0<<n)' isolates the bits to be moved, '<< i-n' moves them to
}                                               // the most left position possible
