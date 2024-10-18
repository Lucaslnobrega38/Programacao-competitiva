#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,l,h;
    cin >> n >> l >> h;

    int nums[n];
    int marks[n];

    int MIN = numeric_limits<int>::min();

    int res = MIN;

    for (int i=0;i<n;i++) cin >> nums[i];

    for (int i=0;i<n;i++) cin >> marks[i];

    // dp[k][i]
    vector<vector<int>> dp(h+1,vector<int>(n ,MIN));

    if (marks[0])
    {
        dp[0][0] = 0;
        dp[1][0] = nums[0];
    }
    else
    {
        dp[0][0] = max(0,nums[0]);
    }

    for (int i=1;i<n;i++)
    {
        for (int j=0;j<=h;j++)
        {
            if (marks[i])
            {
                if (j == 0) {dp[j][i] = 0;}
                else
                {
                    if (dp[j-1][i-1] != MIN)
                    {
                        dp[j][i] = dp[j-1][i-1] + nums[i];
                    }
                }

            }
            else
            {
                if (j == 0) {dp[0][i] = max(0,dp[j][i-1] + nums[i]);}
                else
                {
                    if (dp[j][i-1] != MIN) dp[j][i] = dp[j][i-1] + nums[i];
                }
            }
        }

        for (int j=l;j<=h;j++)
        {
            if (dp[j][i] != MIN)
            {
                res = max(res,dp[j][i]);
            }
        }
    }

    cout << res;
    return 0;
}