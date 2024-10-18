#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main()
{
    int N,K,C;
    cin >> N >> K >> C;

    int dp[K+1][N];
    memset(dp,0,sizeof(dp));
    int arr[N];
    for (int i=0;i<N;i++) {cin >> dp[0][i]; arr[i] = dp[0][i];}

    for (int i=1;i<N;i++) dp[0][i] += dp[0][i-1];

    int res = INT_MIN;
    for (int k = 1;k<=K;k++)
    {
        for (int i = k*C;i<N;i++)
        {
            dp[k][i] = max(dp[k-1][i-C],dp[k][i-1]+arr[i]);
        }
    }



    cout << dp[K][N-1];
}