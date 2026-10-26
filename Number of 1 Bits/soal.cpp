#include <iostream>
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

int hammingWeight(int n)
{
    if (n == 0)
    {
        return 0;
    }
    string binaryN = IntegerToBinary(n);
    long long result = 0;

    for (int i = 0; i < binaryN.size(); i++)
    {
        if (binaryN[i] == '1')
        {
            result++;
        }
        else
        {
            continue;
        }
    }
    return result;
}

int main()
{
    int n = 11;
    cout << hammingWeight(n);
}