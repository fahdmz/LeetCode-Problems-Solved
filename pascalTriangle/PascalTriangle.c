#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **generate(int numRows, int *returnSize, int **returnColumnSizes)
{
    *returnSize = numRows;
    int **result = malloc(numRows * sizeof(int *));     // pointer to a pointer to integer
    *returnColumnSizes = malloc(numRows * sizeof(int)); // pointer to the value it holds

    for (int i = 0; i < numRows; i++)
    {
        (*returnColumnSizes)[i] = i + 1;
        result[i] = malloc((i + 1) * sizeof(int));

        result[i][0] = result[i][i] = 1;

        for (int j = 1; j < i; j++)
        {
            result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
        }
    }
    return result;
}
/*
[1], length = 1
[1, 1], length = 2
[1, 2, 1], length = 3
[1, 2, 2, 1], length = 4
[1, 3, 4, 3, 1], length = 5

C(0, 0) = 1
n!/ n!(n - r)!
n! = n . (n - 1)


*/