#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int res = 1;

    int arr[n];

    for (int i=0;i<n;i++) cin >> arr[i];

    vector<int> dp(n,1);
    
    

    for (int i=0;i<n;i++)
    for (int j=i+1;j<n;j++)
    {
        if (arr[j] > arr[i])
        {
            dp[j] = max(dp[i]+1,dp[j]);
            res = max(dp[j],res);
        }
    }

    cout << res;
}