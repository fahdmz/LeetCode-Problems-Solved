#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
{

    if (nums1.size() > static_cast<size_t>(m))
    {
        nums1.erase(nums1.begin() + m, nums1.end());
    }

    nums1.insert(nums1.end(), nums2.begin(), nums2.end());
    std::sort(nums1.begin(), nums1.end());
}
void printVector(const std::vector<int> &vec)
{
    std::cout << "[ ";
    for (int num : vec)
    {
        std::cout << num << " ";
    }
    std::cout << "]\n";
}

int main()
{
    // --- Test Case 1: Standard Case ---
    // nums1 has a capacity of 6, but only 3 valid elements (m=3)
    std::vector<int> nums1_ex1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> nums2_ex1 = {2, 5, 6};
    int m1 = 3, n1 = 3;

    std::cout << "Test 1 Before: ";
    printVector(nums1_ex1);

    merge(nums1_ex1, m1, nums2_ex1, n1);

    std::cout << "Test 1 After:  ";
    printVector(nums1_ex1); // Expected output: [ 1 2 2 3 5 6 ]
    std::cout << "---------------------------\n";

    // --- Test Case 2: Empty nums2 ---
    std::vector<int> nums1_ex2 = {1};
    std::vector<int> nums2_ex2 = {};
    int m2 = 1, n2 = 0;

    merge(nums1_ex2, m2, nums2_ex2, n2);
    std::cout << "Test 2 After:  ";
    printVector(nums1_ex2); // Expected output: [ 1 ]
    std::cout << "---------------------------\n";

    // --- Test Case 3: Empty initial nums1 ---
    std::vector<int> nums1_ex3 = {0};
    std::vector<int> nums2_ex3 = {1};
    int m3 = 0, n3 = 1;

    merge(nums1_ex3, m3, nums2_ex3, n3);
    std::cout << "Test 3 After:  ";
    printVector(nums1_ex3); // Expected output: [ 1 ]

    return 0;
}
/*
kasus kalo array[i] == 0
kasus kalo array[i] salah satunya 0


nums1 = [1,2,3,0,0,0], m = 3 -> berarti yang valid itu index 0, 1, 2
nums2 = [2,5,6],n = 3 -> berarti yang valid itu 0, 1, 2
k = 5; (6) - 1

[1, 2, 3]
*/