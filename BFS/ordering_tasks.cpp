#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

// 1 indexado

int n,m;
int a,b;

class grafo
{
public:
    int size;
    vector<int> *container;
    vector<int> grau;

    grafo(int arg)
    {
        size = arg+1;
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
        vector<int> res;

        for (int i=1;i<size;i++)
        {
            if (grau[i] == 0)
                fila.push(i);
        }

        int frente;

        while (!fila.empty())
        {
            frente = fila.front();
            fila.pop();
            res.push_back(frente);

            for (int v : container[frente])
            {
                grau[v]--;

                if (grau[v] == 0) fila.push(v);
            }
        }

        return res;
    }

};


int main(){while(1)
{

    cin >> n >> m;

    if (n == 0 && m == 0){return 0;}

    grafo meug(n); // 1 indexado

    for (int i=0;i<m;i++)
    {
        cin >> a >> b;
        meug.add(a,b);
    }

    vector<int> res = meug.solve();

    for (int x : res) cout << x << " ";

    cout << endl;
}}