#include <bits/stdc++.h>
using namespace std;

int dp[1000] = {0};

int solve(int n,int k)
{
    if (n == 0)
    {
        return 1;
    }

    if (n < 0)
    {
        return 0;
    }

    if (dp[n] != 0)
    {
        return dp[n];
    }

    int res = 0;
    for (int i=1;i<=k;i++)
    {
        res += solve(n-1,k);
    }

    return dp[n] = res;

    
}

int main()
{
    int n,k;
    cin >> n >> k;

    solve(n,k);
}