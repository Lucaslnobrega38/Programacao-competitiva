#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n;
   cin >> n;

   char mapa[n][n];

   for (int i=0;i<n;i++)
   for (int j=0;j<n;j++)
        cin >> mapa[i][j];

    int dp[n][n];

    if (mapa[0][0] == '*' or mapa[n-1][n-1] == '*')
    {
        cout << 0;
        return 0;
    }

    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (i < n-1)
            {
                if (mapa[i+1][j] == '.')
                {
                    dp[i+1][j] += dp[i][j];
                    dp[i+1][j] %= 1000000007;
                }
            }

            if (j < n-1)
            {
                if (mapa[i][j+1] == '.')
                {
                    dp[i][j+1] += dp[i][j];
                    dp[i][j+1] %= 1000000007;
                }
            }
        }
    }

    cout << dp[n-1][n-1];
   
}