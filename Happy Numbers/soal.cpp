#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <cmath>
using namespace std;

vector<int> pemisahan(int n)
{
    vector<int> result;

    while (n > 0)
    {
        int temp = n % 10;
        result.push_back(temp);
        n /= 10;
    }
    reverse(result.begin(), result.end());

    return result;
}

int hasilKuadrat(vector<int> lmao)
{
    int result = 0;

    for (int i = 0; i < lmao.size(); i++)
    {
        result += pow(lmao.at(i), 2);
    }
    return result;
}

bool isHappy(int n)
{
    unordered_set<int> visited;

    while (n != 1)
    {
        if (visited.count(n))
        {
            return false;
        }

        visited.insert(n);

        vector<int> result = pemisahan(n);
        n = hasilKuadrat(result);
    }

    return true;
}

int main()
{
    int n = 2;

    if (isHappy(n))
    {
        cout << "Benar";
    }
    else
    {
        cout << "Salah";
    }
}

/*
1532

*/