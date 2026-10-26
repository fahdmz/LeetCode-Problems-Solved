#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int searchInsert(int *nums, int numsSize, int target)
{
    bool found = false;
    int low = 0;
    int high = numsSize - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
        {
            return mid;
            found = true;
        }
        if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    found = false;
    int index = 0;

    if (found == false)
    {
        for (int i = 0; i < numsSize; i++)
        {
            if (target > nums[i])
            {
                index++;
            }
        }
    }
    return index;
}

/*
10
0
3
mid = 0 + 10 - 0 / 2
target < mid
low = mid + 1

1 , 2, 3, 4
target 5
1 2 3 4
*/