#include <bits/stdc++.h>
using namespace std;

#define p int

class grafo
{
public:
    int size;
    vector<p> *container;
    unsigned int log = log2(10000)+1;
    vector<vector<int>> par;
    vector<int> profs;

    grafo(int arg)
    {
        size = arg;
        container = new vector<p>[size];
        par = vector<vector<int>>(size,vector<int>(log,0));
        profs = vector<int>(size,0);
    }

    void add(int de,int para)
    {
        container[de].push_back(para);
        container[para].push_back(de);
    }

    void dfsaux(int node,int parent,int depth)
    {   
        par[node][0] = parent;
        profs[node] = depth;

        for (int v : container[node])
        {
            if (v != parent)
                dfsaux(v,node,depth+1);
        }
    }

    void dfs(int source=1)
    {
        dfsaux(source,0,0);
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
    int t;
    cin >> t;

    int n;
    int m;
    int temp;
    int q;
    int v,w;
    for (int attempt = 1;attempt<=t;attempt++)
    {
        cout << "Case " << attempt << ":\n";
        cin >> n;
        grafo meug(n+1);

        for (int i=1;i<=n;i++)
        {
            cin >> m;
            for (int j=0;j<m;j++)
            {
                cin >> temp;
                meug.add(i,temp); 
            }
        }

        cin >> q;
        meug.dfs();
        meug.blift();


        while (q--)
        {
            cin >> v >> w;
            cout << meug.lca(v,w) << "\n";
        }
    }
}