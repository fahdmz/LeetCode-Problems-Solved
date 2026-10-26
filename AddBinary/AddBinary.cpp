#include <iostream>
#include <string>
using namespace std;

unsigned long long binaryStringToInteger(string a)
{
    // if (a == "0")
    // {
    //     return 0;
    // }
    unsigned long long sum = 0;
    int multiplier = a.length() - 1;
    for (int i = 0; i < a.length(); i++)
    {
        sum = sum + (pow(2, multiplier) * stoi(string(1, a[i])));
        // cout << sum << endl;
        multiplier--;
    }
    return sum;
}

string addBinary(string a, string b)
{
    unsigned long long aInt = binaryStringToInteger(a);
    unsigned long long bInt = binaryStringToInteger(b);
    unsigned long long sum = aInt + bInt;
    if (sum == 0)
    {
        return "0";
    }
    string result = "";
    while (sum > 0)
    {
        unsigned long long sisa = sum % 2;
        result += to_string(sisa);
        sum = sum / 2;
    }

    reverse(result.begin(), result.end());

    return result;
}

// int main()
// {
//     string a = "0";
//     string b = "0";

//     string result = addBinary(a, b);
//     cout << result;
// }

/*
1 0 1 1 =

6 / 2 =
*/