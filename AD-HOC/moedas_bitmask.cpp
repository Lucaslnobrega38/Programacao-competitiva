#include <bits/stdc++.h>
using namespace std;

int v,m;
vector<int> moedas;

bool comp(int a,int b)
{
    return (a>b);
}

void solve()
{
    for (long long i=1;i<(1LL<<m);i++)
    {
        long long soma = 0;
        for (int bit = 0;bit<m;bit++)
        {

            if (i&(1<<bit))
            {
                soma += moedas[bit];
            }
        }

        if (soma == v){cout << "S"; return;}
    }

    cout << "N";
}
int main()
{

    cin >> v >> m;
    moedas = vector<int>(m);

    for (int i=0;i<m;i++)
    {
        cin >> moedas[i];
    }



    solve();

   return 0;


}