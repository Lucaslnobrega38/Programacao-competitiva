#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class grafo
{
public:

    vector<vector<char>> parents;
    vector<vector<char>> mat;
    int l,c;

    pair<int,int> start;
    vector<pair<int,int>> monsters;

    pair<int,int> vic = {-1,-1};

    grafo(int argx,int argy)
    {
        l = argx;
        c = argy;
        mat.resize(l,vector<char>(c));
        parents.resize(l,vector<char>(c));
    }

    void bfs()
    {
        vector<vector<bool>> visited(l,vector<bool>(c,false));
        queue<array<int,3>> fila;

        int vcid = monsters.size();
        for (int i=0;i<vcid;i++)
        {
            fila.push({monsters[i].first,monsters[i].second,i});
            visited[monsters[i].first][monsters[i].second] = true;
        }
        
        fila.push({start.first,start.second,vcid});
        visited[start.first][start.second] = true;

        array<int,3> frente;
        int flin;
        int fcol;
        int fid;

        while (!fila.empty())
        {
            frente = fila.front();
            fila.pop();

            flin = frente[0];
            fcol = frente[1];
            fid = frente[2];

            if (fid != vcid)
            {
                if (flin > 0 and mat[flin-1][fcol] == '.')
                {
                    if (!visited[flin-1][fcol])
                    {
                        visited[flin-1][fcol] = true;
                        fila.push({flin-1,fcol,fid});
                    }
                }

                if (fcol > 0 and mat[flin][fcol-1] == '.')
                {
                    if (!visited[flin][fcol-1])
                    {
                        visited[flin][fcol-1] = true;
                        fila.push({flin,fcol-1,fid});
                    }
                }

                if (flin < (l-1) and mat[flin+1][fcol] == '.')
                {
                    if (!visited[flin+1][fcol])
                    {
                        visited[flin+1][fcol] = true;
                        fila.push({flin+1,fcol,fid});
                    }
                }

                if (fcol < c-1 and mat[flin][fcol+1] == '.')
                {
                    if (!visited[flin][fcol+1])
                    {
                        visited[flin][fcol+1] = true;
                        fila.push({flin,fcol+1,fid});
                    }
                }

            }
            else
            {
                if (flin == 0 or flin == l-1)
                {
                    vic = {flin,fcol};
                    return;
                }

                if (fcol == 0 or fcol == c-1)
                {
                    vic = {flin,fcol};
                    return;
                }

                if (flin > 0)
                {
                    if (!visited[flin-1][fcol] and mat[flin-1][fcol] == '.')
                    {
                        visited[flin-1][fcol] = true;
                        parents[flin-1][fcol] = 'U';
                        fila.push({flin-1,fcol,fid});
                    }
                }

                if (fcol > 0)
                {
                    if (!visited[flin][fcol-1] and mat[flin][fcol-1] == '.')
                    {
                        visited[flin][fcol-1] = true;
                        parents[flin][fcol-1] = 'L';
                        fila.push({flin,fcol-1,fid});
                    }
                }

                if (flin < (l-1))
                {
                    if (!visited[flin+1][fcol] and mat[flin+1][fcol] == '.')
                    {
                        visited[flin+1][fcol] = true;
                        parents[flin+1][fcol] = 'D';
                        fila.push({flin+1,fcol,fid});
                    }
                }

                if (fcol < c-1 and mat[flin][fcol+1] == '.')
                {
                    if (!visited[flin][fcol+1])
                    {
                        visited[flin][fcol+1] = true;
                        parents[flin][fcol+1] = 'R';
                        fila.push({flin,fcol+1,fid});
                    }
                }

            }
        }
    
    }

    void ans()
    {
        cout << "YES" << endl;

        string res = "";
        char c;

        pair<int,int> coords = vic;

        while (coords != start)
        {
            c = parents[coords.first][coords.second];

            res += c;

            if (c == 'U')
            {
                coords.first++;
                continue;
            }

            if (c == 'D')
            {
                coords.first--;
                continue;
            }

            if (c == 'L')
            {
                coords.second++;
                continue;
            }
            else
            {
                coords.second--;
            }
        }
        cout << res.size() << endl;
        for (int i=res.size()-1;i>=0;i--)
        {
            cout << res[i];
        }
    }
    
};

int main()
{
    int n,m;
    cin >> n >> m;

    grafo meug(n,m);

    for (int i=0;i<n;i++)
    for (int j=0;j<m;j++)
    {
        cin >> meug.mat[i][j];

        if (meug.mat[i][j] == 'M')
        {
            meug.monsters.push_back({i,j});
            continue;
        }

        if (meug.mat[i][j] == 'A')
        {
            meug.start = {i,j};
        }
    }

    meug.bfs();

    if (meug.vic.first == -1)
    {
        cout << "NO";
        return 0;
    }

    meug.ans();
}