#include <bits/stdc++.h>
using namespace std;

int n;
int possibilidades = 0;
vector<vector<int>> mat;
int dp[21][1<<21];

long long solve(int mask,int de)
{
    int res = 0;

    if (mask == (1<<n)-1)
    {
        return 1;
    }

    if (dp[de][mask] != -1)
    {
        return dp[de][mask];
    }
    
    for (int i=0;i<1;i++)
    {
        
        // seleciona o primeiro homem
        for (int j=0;j<n;j++)
        {
            // seleciona a mulher

            if ((mask & (1<<j))==0)
            {
                if (mat[de][j]) // se o par é possível
                {
                    res += solve(mask|(1<<j),de+1);
                    res %= 1000000007;
                }
            }

        }

    }

    dp[de][mask] = res;
    return res;
}

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;

    memset(dp,-1,sizeof(dp));

    mat = vector<vector<int>>(n,vector<int>(n));

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cin >> mat[i][j];
        }
    }

    cout << solve(0,0);

}