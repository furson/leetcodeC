#include <stdio.h>
#include <stdlib.h>

int islandPerimeter(int **grid, int gridRowSize, int gridColSize)
{
    //printf("Inside the function\n");
    int i, j, k, allcount;

    allcount = 0;
    for (i = 0; i < gridRowSize; ++i)
    {
        for (j = 0; j < gridColSize; ++j)
            if (grid[i][j] == 1)
            {
                if (j == 0)
                    allcount += 4;
                else
                {
                    if (grid[i][j - 1] == 1)
                        allcount += 2;
                    else
                        allcount += 4;
                }
            }

        /*
        if (rowcount != 0)
            allcount += (rowcount * 2 + 2);
        */

        //printf("allcount is %d\n", allcount);
        if (i != 0)
        {
            for (k = 0; k < gridColSize; ++k)
                if ((grid[i][k] == 1) && (grid[i - 1][k] == 1))
                    allcount -=2;
        }
    }
    return allcount;
}

int main()
{
    int** grid;
    int row = 2;
    int col = 3;
    int i, j;

    grid = (int**)malloc(sizeof(int*) * row);
    for (i = 0; i < row; ++i)
        *(grid + i) = (int*)malloc(sizeof(int) * col);

    for (i = 0; i < row; ++i)
        for (j = 0; j < col; ++j)
            scanf("%d", &grid[i][j]);

    printf("%d\n", islandPerimeter(grid, row, col));
    return 0;
}
