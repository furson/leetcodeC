#include <stdio.h>

#define ARRAYNUM 10

int findPairs(int *nums, int numsSize, int k);

int main()
{
    int i, k;
    int nums[ARRAYNUM];

    for (i = 0; i < ARRAYNUM; ++i)
    {
        scanf("%d", &nums[i]);
        if (nums[i] == 0)
            break;
    }

    scanf("%d", &k);
    printf("%d\n", findPairs(nums, 5, k));

    return 0;
}

int findPairs(int *nums, int numsSize, int k)
{
    int i, j, l, count, eachcount, bigger, smaller;

    count = 0;
    for (i = 0; i < numsSize - 1; ++i)
    {
        bigger = 0;
        smaller = 0;

        j = i + 1;
        for (l = j - 1; l >= 0; --l)
            if (nums[j] == nums[l])
                break;

        if (l >= 0 && j != 1)
            break;

        if (k == 0)
            smaller = 1;

        for (j = i + 1; j < numsSize; ++j)
        {
            if (bigger && smaller)
                break;

            printf("nums[j] - nums[i] = %d\n", nums[j] - nums[i]);
            if (!bigger && (((nums[j] - nums[i] > 0) ? (nums[j] - nums[i]) : (nums[i] - nums[j]))== k))
            {
                printf("j is %d, i is %d\n", j, i);
                bigger = 1;
                count++;
            }
            else if (!smaller && (((nums[j] - nums[i] > 0) ? (nums[j] - nums[i]) : (nums[i] - nums[j]))== k))
            {
                printf("j is %d, i is %d\n", j, i);
                smaller = 1;
                count++;
            }
        }
    }
    return count;
}
