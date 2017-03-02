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
    int i;
    for (i = 1; i <= num; i *= 2)
        num ^= i;
    return num;
}
