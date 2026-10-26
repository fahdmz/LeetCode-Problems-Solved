#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n == 1)
    {
        return 1;
    }
    if (n == 2)
    {
        return 2;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    cin >> n;
    int result = fibonacci(n);
    cout << result;
}

/*
you can only climb stairs with two ways 1 or 2

n == 1 -> 1
n == 2 -> 2
n == 3 -> 3
n == 4 -> 5
n == 5 -> 8

so its a recursive thing -> f(n) = f(n - 1) + f(n - 2) -> fibbonaci


1 1 1 1
1 1 2
1 2 1
2 1 1
2 2

1 1 1 1 1
1 1 1 2
1 1 2 1
1 2 1 1
2 1 1 1
1 2 2
2 1 2
2 2 1


*/