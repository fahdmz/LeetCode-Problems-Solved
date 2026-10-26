#include <stdio.h>
#include "stdlib.h"

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                int *result = (int *)malloc(2 * sizeof(int));
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

/*
Input: nums = [3,3], target = 6
Output: [0,1]

[1, 2, 3, 4] target = 5
  0 1 2
[1, 2]
*/