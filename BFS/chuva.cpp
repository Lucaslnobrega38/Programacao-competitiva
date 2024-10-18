#include <bits/stdc++.h>
using namespace std;

char mat[500][500];
pair<int,int> fonte;
int n,m;

void bfs(pair<int,int> source = fonte)
{
    vector< vector<bool> > visited(500,vector<bool>(500,false));
    queue< pair<int,int> > fila;

    fila.push(source);
    visited[source.first][source.second] = true;

    while (!fila.empty())
    {
        pair<int,int> frente = fila.front();

        if (mat[frente.first+1][frente.second] == '.' && frente.first < n-1)
        {
            mat[frente.first+1][frente.second] = 'o';
            fila.push({frente.first+1,frente.second});
        }

        if (mat[frente.first+1][frente.second] == '#')
        {
            if (mat[frente.first][frente.second+1] == '.')
            {
                mat[frente.first][frente.second+1] = 'o';
                fila.push({frente.first,frente.second+1});
            }

            if (mat[frente.first][frente.second-1] == '.')
            {
                mat[frente.first][frente.second-1] = 'o';
                fila.push({frente.first,frente.second-1});
            }
            
        }

        fila.pop();
    }
}


int main()
{
    cin >> n >> m;

    

    for (int i=0;i<m;i++)
    {
        char temp;
        cin >> temp;
        mat[0][i] = temp;

        if (temp == 'o')
        {
            fonte = {0,i};
        }
    }

    for (int i=1;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            char temp;
            cin >> temp;
            mat[i][j] = temp;

        }
    }

    bfs();

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cout << mat[i][j];
        }

        cout << "\n";
    }
}