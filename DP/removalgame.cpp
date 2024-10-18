#include <bits/stdc++.h>
using namespace std;
#define endl "\n"


int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i=0;i<n;i++) cin >> arr[i];

    pair<long long,long long> dp[n][n];
    // pontos em função de Njogadas e modo
    // 0 = frente
    // 1 = trás 

    for (int i=0;i<n;i++)
    {
        dp[i][i] = {arr[i],0};
    }

    for (int l=1;l<=n;l++)
    {
        for (int i=0;i+l<n;i++)
        {
            int j = i+l;
            if (dp[i+1][j].second+arr[i] > dp[i][j-1].second+arr[j])
            {
                dp[i][j] = {dp[i+1][j].second+arr[i],dp[i+1][j].first};
            }
            else
            {
                dp[i][j] = {dp[i][j-1].second+arr[j],dp[i][j-1].first};
            }
        }
    }

    cout << dp[0][n-1].first;
}