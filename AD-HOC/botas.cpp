#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;


    vector< pair<int,int> > pares(61,{0,0}); // esq,dir


    for (int i=0;i<n;i++)
    {
        int tam;
        char dir_esq;

        cin >> tam >> dir_esq;

        if (dir_esq == 'E')
        {
            pares[tam].first++;
        }
        else
        {
            pares[tam].second++;
        }

    }

    int soma = 0;

    for (int i=30;i<=60;i++)
    {
        soma += min(pares[i].first,pares[i].second);
    }

    cout << soma;
}