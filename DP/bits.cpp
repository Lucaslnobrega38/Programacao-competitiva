#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;

    int potencias[n+1];
    potencias[0] = 1;

    int dp[n+1];

    for (int i=1;i<=n;i++)
    {
        potencias[i] = (2*potencias[i-1])%1000000007;
    }

    for (int i=1;i<=n;i++)
    {
        if (i < k) {dp[i] = potencias[i]; continue;}

        if (i == k){dp[i] = potencias[i]-1;}
        else
        {
            dp[i] = 0;

            for (int minus = 1;minus <= k;minus++)
            {
                dp[i] = (dp[i]+dp[i-minus])%1000000007;
            }
        }
    }

    cout << dp[n]; 
}