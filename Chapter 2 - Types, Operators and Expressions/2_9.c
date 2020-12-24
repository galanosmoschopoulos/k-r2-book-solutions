#include <stdio.h>

int bitcount(unsigned x);

int main() {
    printf("%d\n", bitcount(255));
    return 0;
}

int bitcount(unsigned x)
{
    /*
     * In the binary system, when we reduce a number by 1, all the digits up until the first enabled bit (including this
     * bit) get inverted. So when we compare x and x-1, their parts between the first bit and the first enabled bit
     * are inverted. When we perform bitwise AND operation, the inverted parts turn to 0. Thus, the first enabled bit,
     * which belongs to this part, becomes 0 too.
     */
    int b;
    for(b=0; x != 0; ++b)
        x &= x-1;
    return b;
}
