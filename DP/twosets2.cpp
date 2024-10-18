#include <bits/stdc++.h>
using namespace std;
#define endl "\n"


int main()
{
    int n;
    cin >> n;

    int S = n*(n+1)/2;
    
    if (S&1) {cout << 0; return 0;}

    int s = S/2;

    int dp[n+1][s+1];
    // nums usados x soma

    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    

    for (int sum = 1;sum<=s;sum++)
    {
        for (int used = 1;used<=n;used++)
        {
            dp[used][sum] = dp[used-1][sum-used] + dp[used-1][sum];
            dp[used][sum] %= 1000000007;
        }
    }

    cout << dp[n][s];
}