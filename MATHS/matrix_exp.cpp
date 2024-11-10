#include <bits/stdc++.h>
using namespace std;

class mat
{
public:

    int matriz[2][2];

    mat()
    {
        memset(matriz,0,sizeof(matriz));
    }

    void identidade()
    {
        for (int i=0;i<2;i++)
        {
            matriz[i][i] = 1;
        }
    }

    void add()
    {
        for (int i=0;i<2;i++)
        {
            for (int j=0;j<2;j++)
            {
                cin >> matriz[i][j];
            }
        }
    }

    mat operator*(mat b)
    {
        mat produto;

        for (int i=0;i<2;i++)
        {
            for (int j=0;j<2;j++)
            {
                for (int k =0;k<2;k++)
                {
                    produto.matriz[i][j] += matriz[i][k]*b.matriz[k][j]; 
                }
            }
        }

        return produto;
    }

    void exibe()
    {
        for (int i=0;i<2;i++)
        {
            for (int j=0;j<2;j++)
            {
            cout << matriz[i][j] << " ";
            
            }
        cout << "\n";
        }
    }
};

int fib(int n)
{
    mat res;
    res.identidade();
    mat t;
    t.matriz[0][0] = t.matriz[0][1] = t.matriz[1][0] = 1;
    n -= 2;
    if (n <= 0) return 1;

    while (n)
    {
        if (n&1) res = res*t;

        t = t*t;
        n >>=1;
    }

    return res.matriz[0][0] + res.matriz[0][1];
    
}

int main()
{
    cout << fib(5);
}