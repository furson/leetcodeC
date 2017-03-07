#include <stdio.h>

#define CHARLENGTH 10
//#define MAXINPUT 5


char** findWords(char**, int, int*);
const char* pattern[30] = "QWERTYUIOP\nASDFGHJKL\nZXCVBNM";
const char* littlepattern[30] = "qwertyuiop\nasdfghjkl\nzxcvbnm";

int main()
{
    char (*inputchar)[MAXCHAR];
    char **outputchar;
    int n, *rn, i, j;

    scanf("%d", &n);
    inputchar = (char (*)[MAXCHAR])malloc(sizeof(char *) * n);
    outputchar = (char (*)[MAXCHAR])malloc(sizeof(char *) * n);
    rn = (int*)malloc(sizeof(int));

    outputchar = findWords(inputchar, n, rn);
    for (i = 0; i < rn; ++i)
    {
        for (j = 0; outputchar[i][j] != '\0'; ++j)
            printf("%c", outputchar[i][j]);
        printf("\n");
    }

    return 0;
}

char** findWords(char **words, int wordsSize, int *returnSize)
{
    int i, j, firstpos, pos;

    for (i = 0; i < wordsSize; ++i)
        for (j = 0; words[i][j] != '\0'; ++j)
        {
            if (j == 0)
            {
                for (k = 0; k < 30; ++k)
                    if (words[i][j] == pattern[k] || words[i][j] == littlepattern[k])
                    {
                        firstpos = k;
                        break;
                    }
                if (k == 30)

            }
        }
}
