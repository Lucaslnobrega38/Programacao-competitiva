#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,u;
    cin >> n >> k >> u;
                        // 1 -> 0 indexado
    vector<int> pontos(n+1,0);
    vector< vector<int> > cartelas_com_n(u+1,vector<int>()); // usando exatamente o n
    vector<int> vencedores;

    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<k;j++)
        {
            int temp;
            cin >> temp;

            cartelas_com_n[temp].push_back(i);
        }
    }
    bool out = false;
    for (int i=0;i<u;i++)
    {
        int temp;
        cin >> temp;

        for (int j = 0; j < cartelas_com_n[temp].size();j++)
        {
            pontos[cartelas_com_n[temp][j]] += 1;
            if (pontos[cartelas_com_n[temp][j]] == k){out = true;}
        }

        if (out){break;}
    }

    for (int i=0;i<=n;i++)
    {
        if (pontos[i] == k){cout << i << " ";}
    }
}