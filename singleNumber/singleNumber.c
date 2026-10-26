int searchNumber(int *arr, int val, int length)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == val)
        {
            count++;
        }
    }
    return count;
}

int singleNumber(int *nums, int numsSize)
{
    if (numsSize == 1)
    {
        return nums[0];
    }
    int count;
    for (int i = 0; i < numsSize; i++)
    {
        count = searchNumber(nums, nums[i], numsSize);
        if (count == 1)
        {
            return nums[i];
        }
    }
    return -1;
}