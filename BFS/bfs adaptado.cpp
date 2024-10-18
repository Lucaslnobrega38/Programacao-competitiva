#include <bits/stdc++.h>
using namespace std;

class grafo
{
    public:

    int size;
    int mat[100][100];


    grafo(int arg)
    {
        size = arg;
    }

    void bfs()
    {
        vector< vector<bool> > visitados(size,vector<bool>(size,false));
        vector< vector<int> > dists(size,vector<int>(size,INT_MAX));
        pair<int,int> source = {0,0};
        dists[source.first][source.second] = 0;
        vector<vector<pair<int,int>>> parents(size,vector<pair<int,int>>(size,{-1,-1}));

        queue< pair<int,int> > fila;
        fila.push(source);
        visitados[0][0] = true;

        while(!fila.empty())
        {
            pair<int,int> frente = fila.front();
            fila.pop();
            
            int linha = frente.first;
            int coluna = frente.second;

            if (linha>0)
            {
                    if (dists[linha-1][coluna] > dists[frente.first][frente.second] + mat[linha-1][coluna])
                    {
                        dists[linha-1][coluna] = dists[frente.first][frente.second] + mat[linha-1][coluna];
                        fila.push({linha-1,coluna});
                        parents[linha-1][coluna] = frente;
                        visitados[linha-1][coluna] = true;
                    }
                
            }
            if (linha<size-1)
            {
                if (dists[linha+1][coluna] > mat[linha+1][coluna] + dists[frente.first][frente.second])
                {
                    dists[linha+1][coluna] = mat[linha+1][coluna] + dists[frente.first][frente.second];
                    fila.push({linha+1,coluna});
                    parents[linha+1][coluna] = frente;
                    visitados[linha+1][coluna] = true;
                }
                
            }
            if (coluna > 0)
            {
                if (dists[linha][coluna-1] > dists[frente.first][frente.second] + mat[linha][coluna-1])
                {
                    dists[linha][coluna-1] = dists[frente.first][frente.second] + mat[linha][coluna-1];
                    fila.push({linha,coluna-1});
                    visitados[linha][coluna-1] = true;
                    parents[linha][coluna-1] = frente;
                }

            }
            if (coluna < size-1)
            {
                if (dists[linha][coluna+1] > dists[frente.first][frente.second] + mat[linha][coluna+1])
                {
                    dists[linha][coluna+1] = dists[frente.first][frente.second] + mat[linha][coluna+1];
                    fila.push({linha,coluna+1});
                    visitados[linha][coluna+1] = true;
                    parents[linha][coluna+1] = frente;
                }
                
            }

        }
        cout << dists[size-1][size-1];

    }


};

int main()
{
    int n;
    cin >> n;
    grafo meug(n);

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            int temp;
            cin >> temp;

            meug.mat[i][j] = temp;

        }
    }
    meug.bfs();
}