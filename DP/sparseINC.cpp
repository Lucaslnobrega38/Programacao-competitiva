#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

// sparse table

int dp[1000][11]; // menor elemento de um subarray iniciando em i e com
                // tamanho 2^j. dp[i][j]
int n;
vector<int> arr;

int exp(int a,int b)
{
    int res = 1;

    while (b)
    {
        if (b&1) res *= a;

        a*=a;

        b = b >> 1;
    }

    return res;
}

int main()
{
    cin >> n;
    arr.resize(n);

    for (int i=0;i<n;i++)
    {
        cin >> dp[i][0];
    }

    for (int i=1;i<=10;i++)
    for (int j=0;j<n;j++)
    {
        dp[j][i] = min(dp[j][i-1],dp[j+exp(2,i-1)][i-1])
    }
}