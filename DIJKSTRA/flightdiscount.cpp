#include <bits/stdc++.h>
using namespace std;
#define par pair<long long,int>

class grafo
{
public:

    int size;
    vector<par> *container;

    grafo(int arg)
    {
        size = arg;
        container = new vector<par>[size];
    }

    void add(int de,int para,long long dist)
    {
        container[de].push_back({dist,para});
    }

    vector<long long> dij(int source)
    {
        vector<long long> dists(size,LONG_LONG_MAX);
        priority_queue<par,vector<par>,greater<par>> pq;

        dists[source] = 0;
        pq.push({0,source});

        par frente;

        while (!pq.empty())
        {
            frente = pq.top();
            pq.pop();

            if (frente.first > dists[frente.second]){continue;}

            for (par viz : container[frente.second])
            {
                if (dists[viz.second] > viz.first + frente.first)
                {
                    dists[viz.second] = viz.first+frente.first;
                    pq.push({dists[viz.second],viz.second});
                }
            }
        }
        
        return dists;
    }
}; 

int main()
{
    int n,m;
    cin >> n >> m;

    grafo g(n);
    grafo rg(n);

    int a,b;
    long long c;
    for (int i=0;i<m;i++)
    {
        cin >> a >> b >> c;

        g.add(a-1,b-1,c);
        rg.add(b-1,a-1,c);
    }

    vector<long long> dists = g.dij(0);
    vector<long long> revdists = rg.dij(n-1);

    long long res = LONG_LONG_MAX;

    for (int a = 0;a<n;a++)
    {
        for (par path : g.container[a])
        {
            if (dists[a] == LONG_LONG_MAX or revdists[path.second] == LONG_LONG_MAX) continue;
            
            res = min(res,dists[a]+revdists[path.second]+path.first/2);
        }
    }

    cout << res;
}