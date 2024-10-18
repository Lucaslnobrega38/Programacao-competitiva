#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n,m;

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
        grau.resize(n,0);
    }

    void add(int de,int para)
    {
        container[de].push_back(para);
        grau[para]++;
    }

    void solve()
    {
        priority_queue<int,vector<int>,greater<int>> pq;
        vector<int> res;

        for (int i=0;i<size;i++)
        if (grau[i] == 0) pq.push(i);

        int frente;
        while (!pq.empty())
        {
            frente = pq.top();
            pq.pop();
            res.push_back(frente);

            for (int v : container[frente])
            {
                grau[v]--;

                if (grau[v] == 0) pq.push(v);
            }
        }

        if (res.size() != size){cout << '*' << endl; return;}

        for (int x : res) cout << x << endl;    
    }
};

int main()
{
    cin >> n >> m;

    grafo meug(n);
    int a,b;

    for (int i=0;i<m;i++)
    {
        cin >> a >> b;
        meug.add(a,b);
    }

    meug.solve();

}