#include <stdio.h>
#include <stdlib.h>

int countBattleships(char **board, int row, int col)
{
    int i, j, count;

    count = 0;
    for (i = 0; i < row; ++i)
        for (j = 0; j < col; ++j)
        {
            if (board[i][j] == 'X')
            {
                if ((j == 0 || board[i][j - 1] == '.') && (i == 0 || board[i - 1][j] == '.'))
                    count ++;
                else
                    continue;
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
