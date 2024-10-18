#include <bits/stdc++.h>
using namespace std;

long long dp[100001][101];

int main()
{
    memset(dp,0,sizeof(dp));

    int n,m;
    cin >> n >> m;

    int arr[n];
    for (int i=0;i<n;i++) cin >> arr[i];

    if (arr[0] != 0)
    {
        dp[0][arr[0]] = 1;
    }
    else
    {
        for (int i=0;i<101;i++)
        {
            dp[0][i] = 1;
        }
    }

    for (int i=1;i<n;i++)
    {
        if (arr[i] != 0)
        {
            dp[i][arr[i]] += dp[i-1][arr[i]];

            if (arr[i]+1 <= m) dp[i][arr[i]] += dp[i-1][arr[i]+1];

            if (arr[i]-1 > 0) dp[i][arr[i]] += dp[i-1][arr[i]-1];

            dp[i][arr[i]] %= 1000000007;

        }
        else
        {
            for (int j=1;j<=m;j++)
            {
                dp[i][j] += dp[i-1][j];

                if (j-1 > 0) dp[i][j] += dp[i-1][j-1];
                if (j+1 <= m) dp[i][j] += dp[i-1][j+1];

                dp[i][j] %= 1000000007;
            }
        }
    }
    long long res = 0;
    for (int i=1;i<=m;i++)
    {
        res += dp[n-1][i];
        res %= 1000000007;
    }

    cout << res;
}
