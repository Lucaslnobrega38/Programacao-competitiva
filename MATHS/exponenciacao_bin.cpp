#include <bits/stdc++.h>
using namespace std;

int exp_b(int base, int expoente)
{
    int res = 1;

    while (expoente)
    {
        if (expoente & 1)
        {
            res *= base;
        }

        base*=base;

        expoente = expoente >> 1;
    }

    return res;
}

int main()
{
    int base, expoente;
    cin >> base >> expoente;

    cout << base << " elevado a " << expoente << ": " << exp_b(base,expoente);
}