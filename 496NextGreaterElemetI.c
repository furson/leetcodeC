#include <stdio.h>
#include <stdlib.h>

int* nextGE(int* findNums, int findNumsSize, int* nums, int numSize, int* returnSize)
{
    //printf("Inside the function\n");
    int i, j;
    int inum;
    int *returnarray;

    *returnSize = findNumsSize;
    //printf("%d\n", *returnSize);
    returnarray = (int*)malloc(sizeof(int) * (*returnSize));
    //printf("%d\n", (int)sizeof(returnarray));

    for (i = 0; i < findNumsSize; ++i)
    {
        inum = findNums[i];

        for (j = 0; j < numSize; ++j)
            if (nums[j] == inum)
                break;

        for (; j < numSize; ++j)
            if (inum < nums[j])
                break;

        if (j == numSize)
            returnarray[i] = -1;
        else
            returnarray[i] = nums[j];
    }

    return returnarray;
}

int main()
{
    int findarray[3] = {4, 1, 2};
    int findnum = 3;
    int numarray[4] = {1, 3, 4 ,2};
    int numnum = 4;
    int *returnSize = (int*)malloc(sizeof(int));
    int *retarray;

    //printf("Before the function call\n");
    retarray = nextGE(findarray, findnum, numarray, numnum, returnSize);

    for (int i = 0; i < 3; ++i)
        printf("%d\n", retarray[i]);

    return 0;
}
