#include <bits/stdc++.h>
using namespace std;

class grafoaux
{
public:

    int size;
    vector<int> *container;
    vector<bool> acessible;

    grafoaux(int arg)
    {
        size = arg;
        container = new vector<int>[size];
        acessible.resize(size,false);
    }

    void addinv(int de,int para)
    {
        container[para].push_back(de);
    }

    void dfsaux(int node)
    {
        acessible[node] = true;

        for (int v : container[node])
        {
            if (!acessible[v])
            {
                dfsaux(v);
            }
        }
    }

    void dfs()
    {
        dfsaux(size-1);
    }
};

class edge
{
public:
    int de;
    int para;
    long long peso;
};

edge makedge(int a,int b,long long c)
{
    edge r;
    r.de = a;
    r.para = b;
    r.peso = c;

    return r;
}

class grafo
{
public:
    int size;
    vector<edge> edges;

    grafo(int arg)
    {
        size = arg;
    }

    void add(int de,int para,long long dist)
    {
        edges.push_back(makedge(de,para,dist));
    }
    
    void ford(int source, grafoaux &aux)
    {
        vector<long long> dists(size,LONG_LONG_MAX);
        dists[source] = 0;

        for (int i=0;i<size;i++)
        for (edge e : edges)
        {
            if (dists[e.de] == LONG_LONG_MAX) continue;

            if (dists[e.para] > dists[e.de] + e.peso)
                dists[e.para] = dists[e.de] + e.peso;
        }

        for (edge e : edges)
        {
            if (dists[e.de] == LONG_LONG_MAX) continue;

            if (dists[e.para] > dists[e.de] + e.peso && aux.acessible[e.para])
            {
                cout << -1;
                return;
            }
        }

        cout << -dists[size-1];
    }
};


int main()
{
    int n,m;
    cin >> n >> m;
    grafo meug(n);
    grafoaux aux(n);

    int a,b;
    long long c;
    for (int i=0;i<m;i++)
    {
        cin >> a >> b >> c;
        meug.add(a-1,b-1,-c);

        aux.addinv(a-1,b-1);
    }

    aux.dfs();
    meug.ford(0,aux);

    return 0;
}
