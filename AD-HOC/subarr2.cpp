#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int n,x;
    cin >> n >> x;

    int arr[n];

    for (int i=0;i<n;i++) cin >> arr[i];

    ll soma = 0;
    map<ll,int> freqs;
    freqs[0] = 1;

    ll count = 0;

    for (int i=0;i<n;i++)
    {
        soma += arr[i];
        count += freqs[soma-x];
        freqs[soma]++;
    }

    cout << count;
}


// vr - vl = s
// vl = vr - s