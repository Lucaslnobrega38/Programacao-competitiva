#include <bits/stdc++.h>
using namespace std;

int n,w;
int pesos[100];
long long vals[100];
long long dp[101][100001];

long long mochila(long long peso,int etapa)
{
    if (etapa >= n) return 0;

    if (dp[etapa][peso] != -1) return dp[etapa][peso];

    long long ans = mochila(peso,etapa+1);

    if (peso + pesos[etapa] <= w)
    ans = max(ans,mochila(peso+pesos[etapa],etapa+1)+vals[etapa]);

    dp[etapa][peso] = ans;
    return ans;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    cin >> n >> w;

    for (int i=0;i<n;i++)
    {
        cin >> pesos[i];
        cin >> vals[i];
    }

    cout << mochila(0,0);

}