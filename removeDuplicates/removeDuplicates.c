#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int *nums, int numsSize)
{
    if (numsSize == 0)
        return 0;

    int index = 1;
    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] != nums[i - 1])
        {
            nums[index] = nums[i];
            index++;
        }
    }
    return index;
}

/*
[1, 1, 2, 3, 4]
-> [1, 2, 3, 4, _]
*/