#include <bits/stdc++.h>
using namespace std;

int n,h,l,r,a,dp[2001][2001],sum,res;

int main()
{
    cin >> n >> h >> l >> r;

    sum = 0;

    dp[0][0] = 0;

    res = 0;

    for (int i=1;i<=n;i++)
    {
        cin >> a;
        sum += a;

        for (int j=0;j<=i;j++)
        {
        
            dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]);

            if (((sum-j)%h) >= l && (((sum-j)%h) <=r)) dp[i][j]++;

            if (i == n)
            res = max(res,dp[i][j]);
        }

    }

    cout << res;
}