#include <stdio.h>

#define TABLE_SIZE 100

int binsearch(int x, int v[], int n);
int main()
{
    int i;
    int table[TABLE_SIZE];

    //Create an array with the multiples of 2 from 0 to 198
    for (i = 0; i < TABLE_SIZE; ++i) {
        table[i] = 2*i;
    }
    printf("%d\n", binsearch(198, table, TABLE_SIZE));

    return 0;
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n-1;
    while (low <= high && x != v[mid]) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return (x == v[mid])?mid:-1;
}