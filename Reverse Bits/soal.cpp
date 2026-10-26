#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

string IntegerToBinary(int n)
{
    if (n == 0)
    {
        return "0";
    }
    string result = "";

    while (n > 0)
    {
        int lmao = n % 2;
        if (lmao == 0)
        {
            result += "0";
        }
        else
        {
            result += "1";
        }

        n /= 2;
    }

    reverse(result.begin(), result.end());

    while (result.size() < 32)
    {
        result = "0" + result;
    }

    return result;
}

int BinaryToInteger(string s)
{
    int pangkat2 = 0;
    int result = 0;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            result += pow(2, pangkat2);
        }
        else if (s[i] == '0')
        {
            result += 0;
        }

        pangkat2++;
    }

    return result;
}

int reverseBits(int n)
{
    string firstBinary = IntegerToBinary(n);
    reverse(firstBinary.begin(), firstBinary.end());
    int result = BinaryToInteger(firstBinary);
    return result;
}

int main()
{
    int n = 2147483644;
    cout << reverseBits(n);
}

/*
9 -> 1001
9 / 2 = 4 sisa 1
4 / 2 =  2 sisa 0
2 / 2 = 1 sisa 0
1 / 2 = 1


1000
3210
*/