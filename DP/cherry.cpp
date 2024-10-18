#include <bits/stdc++.h>
using namespace std;

int dp[71][71][71]; // linha, c1,c2
int cherryPickup(vector<vector<int>> &mat,int rl,int r1c,int r2c)
{
    if (dp[rl][r1c][r2c] != -1) return dp[rl][r1c][r2c];

    int res = mat[rl][r1c] + mat[rl][r2c];

    if (r1c == r2c) res -= mat[rl][r2c];

    int l = mat.size();
    int c = mat[0].size();

    if (rl == l-1) return res;

    int fnewcol, snewcol;
    int temp = 0;

    for (int i=-1;i<=1;i++)
    for (int j=-1;j<=1;j++)
    {
        fnewcol = r1c + i;
        snewcol = r2c + j;

        if (fnewcol < 0 or fnewcol >= c) continue;
        if (snewcol < 0 or snewcol >= c) continue;

        temp = max(temp,cherryPickup(mat,rl+1,fnewcol,snewcol));
    }

    dp[rl][r1c][r2c] = res + temp;
    return res+temp;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    vector<vector<int>> mat = {{1,0,0,3},{0,0,0,3},{0,0,3,3},{9,0,3,3}};

    cout << cherryPickup(mat,0,0,mat[0].size()-1);
}