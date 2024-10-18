#include<bits/stdc++.h>
using namespace std;

int maxProfit(int k, vector<int> prices) 
{
    int n = prices.size();
    vector<int> dp(n,0);
    
    for (int i=1;i<n;i++)
    {
        for (int j=0;j<i;j++)
        {
            dp[i] = max(dp[i],prices[i]-prices[j]+dp[j]);
        }
        dp[i] = max(dp[i],dp[i-1]);
    }
    
    
    return dp[n-1];
}