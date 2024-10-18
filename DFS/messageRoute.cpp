#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class grafo
{
public:

    vector<int> *container;
    int size;

    grafo(int arg)
    {
        size = arg;
        container = new vector<int>[size];
    }

    void add(int de,int para)
    {
        container[de].push_back(para);
        container[para].push_back(de);
    }

    void solve(int source = 1)
    {
        queue<int> fila;
        vector<int> visited(size,false);
        vector<int> parents(size,-1);

        fila.push(source);
        visited[source] = true;
        parents[source] = source;

        int frente;
        while (!fila.empty())
        {
            frente = fila.front();
            fila.pop();

            for (int viz : container[frente])
            {
                if (!visited[viz])
                {
                    visited[viz] = true;
                    fila.push(viz);
                    parents[viz] = frente;
                }
            }
        }  

        if (!visited[size-1]){cout << "IMPOSSIBLE"; return;}

        vector<int> way;
        frente = size-1;

        while (1)
        {
            way.push_back(frente);
            if (frente == 1) break;
            frente = parents[frente];
            
        }

        cout << way.size() << endl;
        reverse(way.begin(),way.end());
        
        for (auto c : way) cout << c << " ";
    }
};

int main()
{
    int n,m;
    cin >> n >> m;

    grafo meug(n+1);

    int a,b;
    for (int i=0;i<m;i++)
    {
        cin >> a >> b;
        meug.add(a,b);
    }

    meug.solve();
}