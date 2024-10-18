#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,d,a;
    cin >> n >> d >> a;

    int cont = 0;

    while (a != d)
    {
        if (a == n)
        {
            a = 1;
        }
        else
        {
            a++;
        }

        cont++;
    }

    cout << cont;
}