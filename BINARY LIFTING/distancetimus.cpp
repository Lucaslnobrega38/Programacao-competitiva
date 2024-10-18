#include <bits/stdc++.h>
using namespace std;

#define p pair<long long,int>

class grafo
{
public:
    int size;
    vector<p> *container;
    unsigned int log = log2(50000)+1;
    vector<vector<int>> par;
    vector<int> profs;
    vector<int> dists;

    grafo(int arg)
    {
        size = arg;
        container = new vector<p>[size];
        par = vector<vector<int>>(size,vector<int>(log,0));
        profs = vector<int>(size,0);
        dists = vector<int>(size,0);
    }

    void add(int de,int para,long long dist)
    {
        container[de].push_back({dist,para});
        container[para].push_back({dist,de});
    }

    void dfsaux(int node,int parent,int depth,long long dist)
    {   
        par[node][0] = parent;
        profs[node] = depth;
        dists[node] = dist;

        for (auto v : container[node])
        {
            if (v.second != parent)
                dfsaux(v.second,node,depth+1,dist+v.first);
        }
    }

    void dfs(int source=1)
    {
        dfsaux(source,0,0,0);
    }

    void blift()
    {
        for (int i=1;i<log;i++)
        for (int j=1;j<size;j++)
        {
            par[j][i] = par[par[j][i-1]][i-1];
        }
    }

    int lca(int a,int b)
    {
        if (a==b) return a;

        if (profs[a] < profs[b]) swap(a,b);

        int dif = profs[a]-profs[b];

        for (int i=0;i<log;i++)
        {
            if (dif & (1<<i)) a = par[a][i];
        }

        for (int i=log-1;i>=0;i--)
        {
            if (par[a][i] != par[b][i])
            {
                a = par[a][i];
                b = par[b][i];
            }
        }

        if (a == b)
        {
            return a;
        }

        return par[a][0];
    }
};

int main()
{
    int n;
    cin >> n;
    grafo meug(n+1);

    int a,b; long long c;
    for (int i=0;i<n-1;i++)
    {
        cin >> a >> b >> c;
        meug.add(a+1,b+1,c);
    }

    int m;
    cin >> m;

    meug.dfs();
    meug.blift();

    while (m--)
    {
        cin >> a >> b;

        cout << meug.dists[a+1]+meug.dists[b+1]-(2*meug.dists[meug.lca(a+1,b+1)]);

        //cout << meug.dists[a+1] << " ";cout << meug.dists[b+1] << " ";cout << -(2*meug.dists[meug.lca(a+1,b+1)]) << " ";
        cout << "\n";
    }
}