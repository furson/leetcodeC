#include <stdio.h>
#include <stdlib.h>

int countBattleships(char **board, int row, int col)
{
    int **flag;
    int i, j, k, count, isright;

    flag = (int**) malloc(sizeof(int*) * row);
    for (j = 0; j < row; j++)
        flag[j] = (int*) malloc(sizeof(int) * col);

    for (i = 0; i < row; ++i)
        for (j = 0; j < col; ++j)
            flag[i][j] = 0;

    count = 0;
    for (i = 0; i < row; ++i)
        for (j = 0; j < col; ++j)
        {
            if (flag[i][j] == 1)
                continue;
            if (board[i][j] == '.')
            {
                flag[i][j] = 1;
                continue;
            }
            if (board[i][j] == 'X' && flag[i][j] == 0)
            {
		++count;
                printf("i is %d, j is %d\n", i, j);
                if (j + 1 < col && board[i][j + 1] == 'X' && flag[i][j + 1] == 0)
                    isright = 1;
                else if (i + 1 < row && board[i + 1][j] == 'X' && flag[i + 1][j] == 0)
                    isright = 0;
                else
                    continue;

                if (isright)
                {
                    for (k = j + 1; k < col; ++k)
                    {
                        if (board[i][k] == 'X' && flag[i][k] == 0)
                            flag[i][k] = 1;
                        else
                            break;
                    }
                }
                else
                {
                    for (k = i + 1; k < row; ++k)
                    {
                        if (board[k][j] == 'X' && flag[k][j] == 0)
                            flag[k][j] = 1;
                        else
                            break;
                        printf ("flag[%d][%d] is %d\n", k, j, flag[k][j]);
                    }
                }
            }
    }

    return count;
}

int main()
{
    int row, col;
    int i, j;
    char exceptnewline;
    char **data;

    scanf("%d %d", &row, &col);
    printf("row is %d, col is %d\n", row, col);
    data = (char**) malloc(sizeof(char*) * row);
    for (j = 0; j < row; j++)
        data[j] = (char*) malloc(sizeof(char) * col);

    i = 0;
    j = 0;
    while (scanf("%c", &exceptnewline) == 1)
    {
        if (exceptnewline != '\n')
            data[i][j++] = exceptnewline;
        if (j == col)
        {
            j = 0;
            ++i;
        }
    }

#if 0
    for (i = 0; i < row; ++i)
        for (j = 0; j < col; ++j)
        {
            scanf("%c", &exceptnewline);
            printf("%c\n", exceptnewline);
            if (exceptnewline != '\n')
                data[i][j] = exceptnewline;
        }
#endif

#if 1
    for (i = 0; i < row; ++i)
    {
        for (j = 0; j < col; ++j)
            printf("%c", data[i][j]);
        printf("\n");
    }
#endif
    printf("The Battleships' number is %d\n", countBattleships(data, row, col));

    return 0;
}
