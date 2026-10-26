#include <iostream>
#include <string>
#include <map>
using namespace std;

int romanToInt(string s)
{
    map<char, int> romanNumbers;
    romanNumbers['I'] = 1;
    romanNumbers['V'] = 5;
    romanNumbers['X'] = 10;
    romanNumbers['L'] = 50;
    romanNumbers['C'] = 100;
    romanNumbers['D'] = 500;
    romanNumbers['M'] = 1000;

    int result = 0;
    int i = s.length() - 1;
    while (i >= 0)
    {
        if (i == 0)
        {
            result += romanNumbers[s[i]];
            break;
        }
        else
        {
            // i = 2
            if (s[i] == 'V' && s[i - 1] == 'I')
            {
                result += 4;
                i -= 2;
            }
            else if (s[i] == 'X' && s[i - 1] == 'I')
            {
                result += 9;
                i -= 2;
            }
            else if (s[i] == 'L' && s[i - 1] == 'X')
            {
                result += 40;
                i -= 2;
            }
            else if (s[i] == 'C' && s[i - 1] == 'X')
            {
                result += 90;
                i -= 2;
            }
            else if (s[i] == 'D' && s[i - 1] == 'C')
            {
                result += 400;
                i -= 2;
            }
            else if (s[i] == 'M' && s[i - 1] == 'C')
            {
                result += 900;
                i -= 2;
            }
            else
            {
                result += romanNumbers[s[i]];
                i--;
            }
        }
    }
    return result;
}

int main()
{
    int result = romanToInt("LVIII");
    cout << result;
}

/*

LVIII
01234
*/