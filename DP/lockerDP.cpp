#include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

int main()
{
    int n;
    cin >> n;

    unsigned long long dp[n+1];
    memset(dp,0,sizeof(dp));

    dp[0] = 1;

    long long res = 1;
    for (int i=0;i<=n;i++)
    {
        for (int j=i+1;j<=n;j++)
        {
            dp[j] = max(dp[i]*(j-i),dp[j]);     
        }
    }


    cout << dp[n] % (mod);
}