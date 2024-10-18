#include <bits/stdc++.h>
using namespace std;

set<int> getdigs(int arg)
{
    set<int> res;

    for(auto c : to_string(arg))
    {
        res.insert(c-'0');
    }

    return res;
}

int main()
{
    int n;
    cin >> n;

    int dp[n+1];
    memset(dp,63,sizeof(dp));

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 1;
    dp[5] = 1;
    dp[6] = 1;
    dp[7] = 1;
    dp[8] = 1;
    dp[9] = 1;

    for (int i=10;i<=n;i++)
    {
        for (int dig : getdigs(i))
        {
            dp[i] = min(dp[i],dp[i-dig]+1);
        }
    }

    cout << dp[n];
}