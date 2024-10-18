#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,q;
    cin >> n >> q;

    

    int temp = log2(n)+3;
    int mat[temp+1][n];


    for (int i=0;i<n;i++)
    for (int j=0;j<=temp;j++)
    {
        mat[j][i] = -1;
    }

    int a,b;
    for (int i=1;i<n;i++)
    {
        cin >> mat[0][i];
        mat[0][i]--;
    }


    for (int i=1;i<=temp;i++)
    for (int j=0;j<n;j++)
    {
        a = mat[i-1][j];

        if (a == -1)
        {
            mat[i][j] = -1;
            continue;
        }

        mat[i][j] = mat[i-1][a];
    }

    while (q--)
    {
        cin >> a >> b; //e,l
        a--;

        for (int i=0;i<=temp;i++)
        {
            if (b & (1<<i)) a = mat[i][a];
            if (a == -1){break;}
        }

        if (a != -1) a++;
        cout << a << "\n";
    }
}