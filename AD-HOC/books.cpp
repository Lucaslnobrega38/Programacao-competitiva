#include <bits/stdc++.h>
using namespace std;
#define endl "\n"


int main()
{
    int n;
    cin >> n;

    int t;
    cin >> t;

    vector<int> arr(n);

    for (int i=0;i<n;i++) cin >> arr[i];

    int i = 0;
    int f = 0;

    int res = 0;

    int sum = 0;

    while (f < n)
    {
        if (arr[f] <= t-sum)
        {
            sum += arr[f];
            f++;
        }
        else
        {
            sum-=arr[i];
            i++;
        }

        res = max(res,f-i);
    }

    cout << res;
}