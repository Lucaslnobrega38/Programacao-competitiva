#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n,k;
int total;
vector<int> arr;

void solve(int etapa,int contagem,long long valor)
{
    if (valor > n) return;

    if (etapa == k)
    {
        if (contagem == 0) return;

        if (contagem & 1)
        {
            total += (n/valor);
        }
        else
        {
            total -= (n/valor);
        }

        return;
    }

    solve(etapa+1,contagem,valor);
    solve(etapa+1,contagem+1,valor*arr[etapa]);
}

int main()
{
    cin >> n >> k;
    arr.resize(k);

    for (int i=0;i<k;i++) cin >> arr[i];

    total = 0;

    solve(0,0,1LL);
    cout << n-total;
}