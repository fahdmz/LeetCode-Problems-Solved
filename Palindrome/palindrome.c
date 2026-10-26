#include <stdbool.h>
#include <stdio.h>
#include <math.h>

bool isPalindrome(int x)
{

    if (x < 0)
    {
        return false;
    }
    int reversed = 0;
    int remainder;
    int original = x;

    while (x != 0)
    {
        remainder = x % 10;
        reversed = reversed * 10 + remainder;
        x /= 10;
    }
    if (reversed == original)
    {
        return true;
    }
    return false;
}

int main()
{
    bool krk;
    krk = isPalindrome(1234567899);
    if (krk == true)
    {
        printf("bener");
    }
    else
    {
        printf("false");
    }
}

/*
121 -> 100 + 20 + 1

*/