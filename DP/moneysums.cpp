#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i=1;i<=n;i++) cin >> arr[i];

    int maxs = 1000*n;
    bool dp[maxs+1][n+1];
    // se é possivel fazer soma s com i moedas

    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;

    for (int i=1;i<=n;i++)
    {
        for (int sum=0;sum<=maxs;sum++)
        {
            dp[sum][i] = dp[sum][i-1];

            if (sum-arr[i] >= 0)
            {
                dp[sum][i] = dp[sum][i] bitor dp[sum-arr[i]][i-1];
            }
        }
    }
    vector<int> res;

    for (int vals = 1;vals<=maxs;vals++)
    {
        if (dp[vals][n])
        {
            res.push_back(vals);
        }
    }

    cout << res.size() << endl;

    for (auto x : res) cout << x << " ";
}