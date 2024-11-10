#include <bits/stdc++.h>
using namespace std;

long long pesos[100];
int valores[100];

long long dp[101][100001];
bool dpaux[101][100001];


int n;
long long w;

int main()
{
    // a maneira de resolver agora é com dp em tabela.
    // como os pesos agora são grandes, a tabela é do tipo
    // qtd X valor, sendo qtd a quantidade de elementos escolhidos,
    // cria-se uma tabela auxiliar booleana para controlar quais 
    // valores são possíveis, e na tabela principal, insere-se o 
    // menor peso necessário para a determinada quantidade de elementos.
    // TENTAR ITERATIVAMENTE.

    cin >> n >> w;

    for (int i=0;i<n;i++)
    {
        cin >> pesos[i];
        cin >> valores[i];
    }

    for (int i=0;i<101;i++)
    {
        for (int j=0;j<100001;j++)
        {
            dp[i][j] = LONG_LONG_MAX;
        }
    }

    dpaux[0][0] = true;
    dp[0][0] = 0;

    int res = INT_MIN;

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<100001;j++)
        {
            if (dpaux[i][j])
            {
                dpaux[i+1][j] = true;
                dp[i+1][j] = min(dp[i+1][j],dp[i][j]);

                if (dp[i][j]+pesos[i] <= w)
                {
                    dpaux[i+1][j+valores[i]] = true;
                    dp[i+1][j+valores[i]] = min(dp[i+1][j+valores[i]],dp[i][j]+pesos[i]);
                    res = max(res,j + valores[i]);
                }
            }   

        }
    }

    
    //for (int i=0;i<=n;i++) {  for (int j=0;j<=res;j++){    cout << dp[i][j] << " ";}cout << endl;}
    cout << res;
    
}