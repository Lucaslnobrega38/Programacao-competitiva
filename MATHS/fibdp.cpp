#include <bits/stdc++.h>
using namespace std;

// 1 1 2 3 5 8 13 21 34 55
// 0 1 2 3 4 5  6  7  8  9 

int dp[1000];


int fib(unsigned int n)
{
    if (n <= 2)
    {
        return 1;
    }
    else
    {
        return fib(n-1)+fib(n-2);
    }
}

int fibdp(int n)
{

    if (dp[n] != -1)
    {
        return dp[n];
    }
    else
    {
        dp[n] = fibdp(n-1)+fibdp(n-2);
        return dp[n];
    }
}

int main()
{
    memset(dp,-1,sizeof(dp));

    dp[0] = 1;
    dp[1] = 1;

    int n;
    cin >> n;

    cout << fib(n+1) << " " << fibdp(n);
}