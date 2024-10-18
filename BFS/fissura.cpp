#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > mat = vector<vector<int>>(500, vector<int>(500, -1));


int n,f;

void preenche(int forca)
{
    queue< pair<int,int >> fila;
    vector< vector<bool> > visitados(500, vector<bool>(500, false));

    if (mat[0][0] <= forca)
    {
        fila.push({0,0});
        mat[0][0] = 10; // 10 para regioes inundadas
        visitados[0][0] = true;
    }

    while (!fila.empty())
    {
        auto frente = fila.front();
        int cordx = frente.first;
        int cordy = frente.second;
        fila.pop();

        if (cordx > 0)
        {
            if (!visitados[cordx-1][cordy] && mat[cordx-1][cordy] <= f)
            {
                fila.push({cordx-1,cordy});
                visitados[cordx-1][cordy] = true;
                mat[cordx-1][cordy] = 10;
            }
        }

        if (cordx < n-1)
        {
            if (!visitados[cordx+1][cordy] && mat[cordx+1][cordy] <= f)
            {
                fila.push({cordx+1,cordy});
                visitados[cordx+1][cordy] = true;
                mat[cordx+1][cordy] = 10;
            }
        }

        if (cordy > 0)
        {
            if (!visitados[cordx][cordy-1] && mat[cordx][cordy-1] <= f)
            {
                fila.push({cordx,cordy-1});
                visitados[cordx][cordy-1] = true;
                mat[cordx][cordy-1] = 10;
            }
        }

        if (cordy < n-1)
        {
            if (!visitados[cordx][cordy+1] && mat[cordx][cordy+1] <= f)
            {
                fila.push({cordx,cordy+1});
                visitados[cordx][cordy+1] = true;
                mat[cordx][cordy+1] = 10;
            }
        }
    }
}

int main()
{
    cin >> n >> f;

    for (int i =0;i<n;i++)
    {
        string c;
        cin >> c;

        for (int j=0;j<n;j++)
        {
            mat[i][j] = c[j]-'0';
        }
    }

    preenche(f);

    for (int i =0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (mat[i][j] != 10){cout << mat[i][j];}
            else {cout << "*";}
        }

        cout << "\n";
    }




}