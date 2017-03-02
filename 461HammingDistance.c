#include <stdio.h>

int hammingDistance(unsigned int, unsigned int);

int main()
{
    unsigned int x, y;

    scanf("%u %u", &x, &y);
    printf("%u\n", hammingDistance(x, y));

    return 0;
}

int hammingDistance(unsigned int x, unsigned int y)
{
    int i, count;

    count = 0;
    for (i = 0; i < 32; ++i)
    {
        count += (((x & (1U << i)) ^ (y & (1U << i)))) && 1;
        //printf ("count is %d and (1 << i) is %u\n", count, 1 << i);
    }

    return count;
}
