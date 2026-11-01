#include <iostream>
#include <unordered_set>
using namespace std;

bool containsDuplicate(vector<int> &nums)
{
    unordered_set<int> result;
    for (int lmao : nums)
    {
        result.insert(lmao);
    }

    if (result.size() != nums.size())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
}