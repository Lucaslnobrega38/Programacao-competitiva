#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cin >> n >> x;

    int arr[n+1]; // coins, 1 indexado

    for (int i=1;i<=n;i++) cin >> arr[i];

    bool possible[x+1];
    int dp[x+1];
    //quantidade de moedas minima para obter valor j

    memset(dp,63,sizeof(dp));
    memset(possible,false,sizeof(possible));

    dp[0] = 0;
    possible[0] = true;

    for (int soma=0;soma<=x;soma++)
    {
        for (int i=1;i<=n;i++)
        {
            if (arr[i]+soma > x) continue;

            if (possible[soma])
            {
                possible[soma+arr[i]] = true;
                dp[soma+arr[i]] = min(dp[soma]+1,dp[soma+arr[i]]);
            }
        }
    }

    if (!possible[x]){cout << -1; return 0;}

    cout << dp[x];
}