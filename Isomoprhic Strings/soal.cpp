#include <iostream>
#include <unordered_set>
#include <unordered_map>
using namespace std;

vector<int> hitungFrekuensi(string s)
{
    vector<int> hasil;
    unordered_map<char, int> frekuensi;

    for (char c : s)
    {
        frekuensi[c]++;
    }

    for (char c : s)
    {
        if (frekuensi[c] > 0)
        {
            hasil.push_back(frekuensi[c]);
            frekuensi[c] = 0;
        }
    }
    return hasil;
}

bool isIsomorphic(string s, string t)
{
    if (s.size() != t.size())
    {
        return false;
    }
    vector<int> string1 = hitungFrekuensi(s);
    vector<int> string2 = hitungFrekuensi(t);

    if (string1.size() != string2.size())
    {
        return false;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (string1[i] != string2[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string lmao1 = "paper";
    string lmao2 = "title";

    if (isIsomorphic(lmao1, lmao2))
    {
        cout << "Benar";
    }
    else
    {
        cout << "Salah";
    }
}

/*
masukin ke set
hitung frekuensi
bandingin vektornya dan posisinya
kalo sama, return true
*/