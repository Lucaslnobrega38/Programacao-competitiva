#include <bits/stdc++.h>
using namespace std;

bool dp[2000][2000];
//start x end

int main()
{
    memset(dp,false,sizeof(dp));

    int n = s.size();

    if (n == 0) return 0;

    for (int i=0;i<2000;i++) dp[i][i] = true;

    for (int len=2;len<n;len++)
    {
        for (int start=0;start+len-1<n;start++)
        {
            int end = start+len-1;

            if (s[start] == s[end] and (dp[start+1][end-1] or len == 2))
            {
                dp[start][end] = true;
            }
        }
    }

    vector<int> mincuts(n+1,INT_MAX);
    mincuts[0] = 0;

    for (int end =1;end<n;end++)
    {
        if (dp[0][end])
        {
            mincuts[end] = 0;
        }
        else
        {
            for (int start = end; start >= 1;start--)
            {
                if (dp[start][end])
                {
                    mincuts[end] = min(mincuts[end],mincuts[start-1]+1);
                }
            }
        }
    }
    cout << mincuts[n-1];
}