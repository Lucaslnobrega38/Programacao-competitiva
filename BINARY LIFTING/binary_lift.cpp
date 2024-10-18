#include <bits/stdc++.h>
using namespace std;

// BINARY LIFTING

int mat[31][200000];

int main()
{
    ios::sync_with_stdio(0);ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n,q;
    cin >> n >> q;

    for (int i=0;i<n;i++)
    {
        cin >> mat[0][i];
        mat[0][i]--;

        // destino a partir de i, pegando 2^0 teleportadores.
    }


    for (int i=1;i<=30;i++)
    for (int j=0;j<n;j++)
    {
        int a = mat[i-1][j];
        mat[i][j] = mat[i-1][a];
    }

    int start,teleq;

    for (int i=0;i<q;i++)
    {
        cin >> start >> teleq;
        
        int res = start-1;

        for (int j=0;j<31;j++)
        {
            if (teleq & (1<<j)) res = mat[j][res];
        }

        cout << res+1 << endl;
    }


}