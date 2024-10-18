#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[100001];

    memset(arr,0,sizeof(arr));
    int temp;
    for (int i=1;i<=n;i++)
    {
        cin >> temp;
        arr[temp]++;
    }

    long long dp[100002];
    dp[0] = 0;
    dp[1] = arr[1];

    for (int i=2;i<=100001;i++)
    {
        dp[i] = max((long long)dp[i-1],dp[i-2]+arr[i]*1LL*i);
    }

    cout << dp[100000];
}