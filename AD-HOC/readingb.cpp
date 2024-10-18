#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long soma = 0;
    vector<int> arr(n);

    for (int i=0;i<n;i++){cin >> arr[i]; soma += arr[i];}

    sort(arr.begin(),arr.end());

    if (arr[n-1] > (soma-arr[n-1]))
    {
        cout << arr[n-1]*2;
    }
    else
    {
        cout << soma;
    }
}