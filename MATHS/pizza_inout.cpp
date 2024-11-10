#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    ll resin = 0;
    ll resout = 0;
    ll soma = 0;

    for (int i=0;i<n;i++)
    {
        soma += arr[i];
        resout += arr[i];
        arr[i] = -arr[i];
        if (soma < 0) soma = 0;

        resin = max(resin,soma);
    }

    soma = 0;
    ll locout=0;

    for (int i=0;i<n;i++)
    {
        soma += arr[i];

        if (soma < 0) soma = 0;

        locout = max(locout,soma);
    }

    resout += locout;

    cout << max(resin,resout);
}