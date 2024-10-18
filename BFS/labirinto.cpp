#include <bits/stdc++.h>
using namespace std;

class grafo
{
public:

    int l,c;
    vector<vector<char>> mat;
    vector<vector<bool>> visited;
    vector<vector<char>> way;
    pair<int,int> start;
    pair<int,int> end;

    grafo(int linhas,int colunas)
    {
        l = linhas;
        c = colunas;

        mat.resize(l,vector<char>(c));
        visited.resize(l,vector<bool>(c,false));
        way.resize(l,vector<char>(c));
    }

    void retrieve(string &s)
    {
        pair<int,int> coord = {end.first,end.second};
        char c;

        while (coord != start)
        {
            c = way[coord.first][coord.second];
            s += c;

            if (c == 'D')
            {
                coord.first--;
                continue;
            }

            if (c == 'U')
            {
                coord.first++;
                continue;
            }

            if (c == 'R')
            {
                coord.second--;
                continue;
            }

            if (c == 'L')
            {
                coord.second++;
            }


        }
    }

    void solve()
    {
        bfs(start.first,start.second);

        if (visited[end.first][end.second])
        {
            string s = "";
            cout << "YES" << endl;

            retrieve(s);

            cout << s.size() << endl;

            reverse(s.begin(),s.end());

            cout << s;

        }
        else
        {
            cout << "NO";
        }
    }

    void bfs(int si,int sj)
    {
        queue<pair<int,int>> fila;
        fila.push({si,sj});
        visited[si][sj] = true;
        map<pair<int,int>,string> dict;
        dict[{si,sj}] = "";

        pair<int,int> frente;

        while (!fila.empty())
        {
            frente = fila.front();
            fila.pop();

            if (frente.first > 0)
            {
                if (mat[frente.first-1][frente.second] != '#')
                if (!visited[frente.first-1][frente.second])
                {
                    visited[frente.first-1][frente.second] = true;
                    way[frente.first-1][frente.second] = 'U';
                    fila.push({frente.first-1,frente.second});
                }
                
            }

            if (frente.first < l-1)
            {
                if (mat[frente.first+1][frente.second] != '#')
                if (!visited[frente.first+1][frente.second])
                {
                    visited[frente.first+1][frente.second] = true;
                    way[frente.first+1][frente.second] = 'D';
                    fila.push({frente.first+1,frente.second});
                }
            }

            if (frente.second > 0)
            {
                if (mat[frente.first][frente.second-1] != '#')
                if (!visited[frente.first][frente.second-1])
                {
                    visited[frente.first][frente.second-1] = true;
                    way[frente.first][frente.second-1] = 'L';
                    fila.push({frente.first,frente.second-1});
                }
            }

            if (frente.second < c-1)
            {
                if (mat[frente.first][frente.second+1] != '#')
                if (!visited[frente.first][frente.second+1])
                {
                    visited[frente.first][frente.second+1] = true;
                    way[frente.first][frente.second+1] = 'R';
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

        if (meug.mat[i][j] == 'A')
        {
            meug.start = {i,j};
            continue;
        }

        if (meug.mat[i][j] == 'B')
        {
            meug.end = {i,j};
        }
    }

    meug.solve();
}