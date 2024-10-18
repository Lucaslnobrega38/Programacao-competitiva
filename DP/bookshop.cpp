#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main()
{
    int n,x;
    cin >> n >> x;

    int prices[n+1];
    int pages[n+1];

    for (int i=1;i<=n;i++) cin >> prices[i];
    for (int i=1;i<=n;i++) cin >> pages[i];

    int dp[n+1][x+1];
    memset(dp,0,sizeof(dp));
    // pags com 0 a i livros gastando no max j



    for (int i=1;i<=n;i++)
    {
        for (int p=1;p<=x;p++)
        {
            dp[i][p] = dp[i-1][p];

            if (prices[i] <= p)
            {
                dp[i][p] = max(dp[i][p],dp[i-1][p-prices[i]]+pages[i]);
            }
        }
    }

    cout << dp[n][x];
}