#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int dp[n+1];
    memset(dp,0,sizeof(dp));

    dp[0] = 1;
    //dp[1] = 1;

    for (int i=0;i<=n;i++)
    {
        for (int j=1;j<=6 && i+j <= n;j++)
        {
            dp[i+j] += dp[i];
            dp[i+j] %= 1000000007;
        }
    }

    cout << dp[n];
}