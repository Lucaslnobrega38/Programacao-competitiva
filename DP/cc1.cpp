#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    cin >> n >> x;

    int arr[n+1];
    for (int i=1;i<=n;i++) cin >> arr[i];

    int dp[x+1];
    bool possivel[x+1];

    memset(dp,0,sizeof(dp));
    memset(possivel,false,sizeof(possivel));

    dp[0] = 1;
    possivel[0] = true;

    for (int sum=0;sum<=x;sum++)
    {
        if (possivel[sum])
        {
            for (int i=1;i<=n;i++)
            {
                if (sum+arr[i] > x) continue;;

                possivel[sum+arr[i]] = true;
                dp[sum+arr[i]] += dp[sum];

               dp[sum+arr[i]] %= 1000000007;
            }
        }
    }

    cout << dp[x];
}