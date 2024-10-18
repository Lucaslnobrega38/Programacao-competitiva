#include <bits/stdc++.h>
using namespace std;

// dada uma escada de n degraus, calcule o número de maneiras de subí-la,
// considerando que a cada degrau é possível realizar um pulo no máximo de k degraus.

int main()
{
    int n,k;
    cin >> n >> k;

    vector<int> dp(n,0);
    dp[0] = 1;
    dp[1] = 1;



    for (int i=2;i<n;i++)
    {
    
        if (i-k-1 >= 0)
        {
            dp[i] = (2*dp[i-1]) - dp[i-k-1];
        }
        else
        {
            dp[i] = 2*dp[i-1];
        }
    }

    cout << dp[n-1];
}