#include <bits/stdc++.h>
using namespace std;

class grafo
{
public:

    int size;
    vector<int> *container;
    vector<int> grau;

    grafo(int arg)
    {
        size = arg;
        container = new vector<int>[size];
        grau.resize(size,0);
    }

    void add(int antes,int depois)
    {
        container[antes].push_back(depois);
        grau[depois]++;
    }

    void solve()
    {
        vector<int> res;
        queue<int> fila;

        for (int i=1;i<size;i++)
        {
            if (grau[i] == 0)
            {
                fila.push(i);
                res.push_back(i);
            }
        }

        int frente;

        while (!fila.empty())
        {
            frente = fila.front();
            fila.pop();

            for (int v : container[frente])
            {
                grau[v]--;

                if (grau[v] == 0)
                {
                    res.push_back(v);
                    fila.push(v);
                }
            }
        }

        if (res.size() == size-1)
        {
            for (int x : res) cout << x << " ";
        }
        else
        {
            cout << "IMPOSSIBLE";
        }

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