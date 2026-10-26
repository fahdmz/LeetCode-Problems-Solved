#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{
    stack<char> lmao;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            cout << "isi top stack : " << s[i] << endl;
            lmao.push(s[i]);
        }
        else
        {
            if (lmao.empty())
                return false;

            if (s[i] == ')' && lmao.top() != '(')
                return false;
            if (s[i] == '}' && lmao.top() != '{')
                return false;
            if (s[i] == ']' && lmao.top() != '[')
                return false;
            lmao.pop();
        }
    }
    return lmao.empty();
}
int main()
{
    if (isValid("(){}[]"))
    {
        cout << "lmao" << endl;
    }
}