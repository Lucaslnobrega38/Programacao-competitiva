#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> matrix) 
{
    int n = matrix.size();
    int m = matrix[0].size();
    
    vector<vector<int>> dp = matrix;
    
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            if (i < (n-1))
            {
                dp[i+1][j] = max(dp[i+1][j], dp[i][j]+matrix[i+1][j]);
            }
            
            if (j < (m-1))
            {
                dp[i][j+1] = max(dp[i][j+1],dp[i][j]+matrix[i][j+1]);
            }
        } //receba
    }
    return dp[n-1][m-1];
}