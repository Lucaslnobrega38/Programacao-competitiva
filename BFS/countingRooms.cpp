#include <bits/stdc++.h>
using namespace std;

class grafo
{
public:

    int l,c;
    vector<vector<char>> mat;
    vector<vector<bool>> visited;

    grafo(int linhas,int colunas)
    {
        l = linhas;
        c = colunas;

        mat.resize(l,vector<char>(c));
        visited.resize(l,vector<bool>(c,false));
    }

    int solve()
    {
        int res = 0;

        for (int i=0;i<l;i++)
        for (int j=0;j<c;j++)
        {
            if (mat[i][j] == '.')
            {
                if (!visited[i][j])
                {
                    bfs(i,j);
                    res++;
                }
            }

        }

        return res;
    }

    void bfs(int si,int sj)
    {
        queue<pair<int,int>> fila;
        fila.push({si,sj});
        visited[si][sj] = true;

        pair<int,int> frente;
        while (!fila.empty())
        {
            frente = fila.front();
            fila.pop();

            if (frente.first > 0)
            {
                if (mat[frente.first-1][frente.second] == '.')
                if (!visited[frente.first-1][frente.second])
                {
                    visited[frente.first-1][frente.second] = true;
                    fila.push({frente.first-1,frente.second});
                }
                
            }

            if (frente.first < l-1)
            {
                if (mat[frente.first+1][frente.second] == '.')
                if (!visited[frente.first+1][frente.second])
                {
                    visited[frente.first+1][frente.second] = true;
                    fila.push({frente.first+1,frente.second});
                }
            }

            if (frente.second > 0)
            {
                if (mat[frente.first][frente.second-1] == '.')
                if (!visited[frente.first][frente.second-1])
                {
                    visited[frente.first][frente.second-1] = true;
                    fila.push({frente.first,frente.second-1});
                }
            }

            if (frente.second < c-1)
            {
                if (mat[frente.first][frente.second+1] == '.')
                if (!visited[frente.first][frente.second+1])
                {
                    visited[frente.first][frente.second+1] = true;
                    fila.push({frente.first,frente.second+1});
                }
            }

        }
    }

};

int main()
{
    int l,c;
    cin >> l >> c;

    grafo meug(l,c);

    for (int i=0;i<l;i++)
    for (int j=0;j<c;j++)
    {
        cin >> meug.mat[i][j];
    }

    cout << meug.solve();
}