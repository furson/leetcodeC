#include <stdio.h>

int findComplement(int);

int main()
{
    int num;

    scanf("%d", &num);
    printf("%d\n", findComplement(num));

    return 0;
}

int findComplement(int num)
{
    int ans, count;

    count = 0;
    ans = (~0) ^ num;

    while (num)
    {
        num >>= 1;
        ++count;
    }

    while (count)
    {
        num <<= 1;
        num += 1;
        --count;
    }
    ans &= num;

    return ans;
}
