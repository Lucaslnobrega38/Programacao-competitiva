#include <bits/stdc++.h>
using namespace std;

#define p pair<long long, int>

class grafo
{
public:
    int size;
    vector<p> *container;
    vector<vector<int>> par;
    vector<int> depths;
    vector<long long> dists;
    int log;

    grafo(int arg)
    {
        log = log2(arg)+1; // bad alloc
        size = arg;
        container = new vector<p>[size+1];
        par = vector<vector<int>>(size+1,vector<int>(log,0));
        depths = vector<int>(size+1);
        dists = vector<long long>(size+1);
        dists[0] = 0;
        dists[1] = 0;
    } 

    void add(int de,int para, long long dist)
    {
        container[de].push_back({dist,para});
        container[para].push_back({dist,de});
    }

    void dfsaux(int node,int parent,int depth,long long dist)
    {
        par[node][0] = parent;
        depths[node] = depth;
        dists[node] = dist;

        for (auto viz : container[node])
        {
            if (viz.second != parent)
            dfsaux(viz.second,node,depth+1,dist+viz.first);
        }
    }

    void dfs(int source = 1)
    {
        dfsaux(source,0,0,0);
    }

    void blifting()
    {
        for (int i=1;i<log;i++)
        for (int j=1;j<=size;j++)
        {
            par[j][i] = par[par[j][i-1]][i-1];
        }
    }

    int lca(int a,int b)
    {
        if (a==b) return a;
        int res;
        if (depths[a] < depths[b]) swap(a,b);

        int diff = depths[a] - depths[b];

        for (int i=0;i<=log;i++)
        {
            if (diff & (1<<i)) a = par[a][i];
        }

        for (int i=log;i>=0;i--)
        {
            if (par[a][i] != par[b][i])
            {
                a = par[a][i];
                b = par[b][i];
            }
        }

        return par[a][0];
    }

};

int main()
{
    int n;
    cin >> n;
    while (1)
    {
        if (n==0){break;}

        grafo meug(n);
        int b;
        long long dist;
        for (int i=1;i<=n-1;i++)
        {
            cin >> b >> dist;
            meug.add(i+1,b+1,dist);
        }

        meug.dfs();
        meug.blifting();
        
        int q;
        cin >> q;
        int a;
        int lca;
        for (int i=0;i<q;i++)
        {
            cin >> a >> b;
            a++,b++;
            lca = meug.lca(a,b);

            cout << meug.dists[a]-meug.dists[lca]-meug.dists[lca]+meug.dists[b] << " ";
        }
        cout << endl;
        cin >> n;
    }
    return 0;
}
