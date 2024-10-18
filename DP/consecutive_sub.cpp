#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main()
{
    int n;
    cin >> n;

    int maxv = 0;
    int last;

    int arr[n];

    for (int i=0;i<n;i++) cin >> arr[i];

    map<int,int> dp;

    for (int i=0;i<n;i++)
    {
        dp[arr[i]] = max(dp[arr[i]],dp[arr[i]-1]+1);

        if (maxv < dp[arr[i]])
        {
            maxv = dp[arr[i]];
            last = i;
        }
    }

    vector<int> res;
    res.push_back(last+1);

    for (int i=last-1;i>=0;i--)
    {
        if (arr[i] == arr[last]-1)
        {
            res.push_back(i+1);
            last = i;
        }
    }

    reverse(res.begin(),res.end());

    cout << res.size() << endl;

    for (int x : res) cout << x << " ";
}