#include <bits/stdc++.h>
using namespace std;



int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int v,m;
    cin >> v >> m;

    bool dp[v+1];
    memset(dp,false,sizeof(dp));

    dp[0] = true;


    vector<int> coins(m);

    for (int i=0;i<m;i++)
    {
        cin >> coins[i];
    }

    for (auto moeda : coins)
    {
        for (int i=v;i-moeda>=0;i--)
        {
            if (dp[i-moeda])
            {
                dp[i] = true;
            }
        }
    }

    if (dp[v]){cout << "S\n";}
    else{cout << "N\n";}



}