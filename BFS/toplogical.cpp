#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

// ordenação topológica

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

    void add(int de,int para)
    {
        container[de].push_back(para);
        grau[para]++;
    }

    vector<int> solve()
    {
        queue<int> fila;
        vector<int> ordem;

        for (int i=0;i<size;i++)
        {
            if (grau[i] == 0) fila.push(i);
        }

        int frente;
        while (!fila.empty())
        {
            frente = fila.front();
            ordem.push_back(frente);
            fila.pop();

            for (int v : container[frente])
            {
                grau[v]--;

                if (grau[v] == 0)
                {
                    fila.push(v);
                }
            }
        }

        return ordem;
    }
};

int main()
{
    int n,m;
    cin >> n >> m;

    grafo meug(n+1); // 1 indexed

    int a,b;

    for (int i=0;i<m;i++)
    {
        cin >> a >> b;
        meug.add(a,b);
    }

    vector<int> ordem = meug.solve();

    if (ordem.size() < n)
    {
        cout << "impossivel";
    }
    else
    {
        for (int i : ordem) cout << i << " ";
    }
}