#include <bits/stdc++.h>
using namespace std;

vector<int> ordem;
int id = 0;

class grafo
{
public:
    int size;
    int ts;
    vector<int> *g;
    vector<int> *r;
    vector<int> visited;
    vector<int> comp;
    vector<bool> res;

    grafo(int arg)
    {
        size = arg;
        ts = arg*2;
        g = new vector<int>[ts];
        r = new vector<int>[ts];
        visited.resize(ts,false);
        comp.resize(ts);
        res.resize(size);
    }

    void add(int a,int b)
    {
        g[a].push_back(b);
        r[b].push_back(a);
    }

    void dfs1(int node)
    {
        visited[node] = true;

        for (int v : g[node])
        {
            if (!visited[v]) dfs1(v);
        }

        ordem.push_back(node);
    }

    void dfs2(int node)
    {
        visited[node] = true;
        comp[node] = id;

        for (int v : r[node])
        {
            if (!visited[v]) dfs2(v);
        }
    }
};

int main()
{
    int n,m;
    cin >> n >> m;

    grafo meug(m);

    int a,b;
    int ainv,binv;
    char as,bs;

    for (int i=0;i<n;i++)
    {
        cin >> as >> a;
        cin >> bs >> b;
        a--, b--; // 0 indexado

        if (as == '+')
        {
            ainv = a+m;
        }
        else
        {
            ainv = a;
            a += m;
        }

        if (bs == '+')
        {
            binv = b+m;
        }
        else
        {
            binv = b;
            b += m;
        }

        meug.add(ainv,b);
        meug.add(binv,a);
    }

    for (int i=0;i<meug.ts;i++)
    {
        if (!meug.visited[i]) meug.dfs1(i);
    }

    reverse(ordem.begin(),ordem.end());
    meug.visited.assign(meug.ts,false);

    for (int i : ordem)
    {
        if (!meug.visited[i]) {meug.dfs2(i); id++;}
    }

    for (int i=0;i<m;i++)
    {
        if (meug.comp[i] == meug.comp[i+m])
        {
            cout << "IMPOSSIBLE";
            return 0;
        }

        meug.res[i] = meug.comp[i] >= meug.comp[i+m];
    }

    for (bool b : meug.res)
    {
        if (b)
        {
            cout << "+ ";
        }
        else
        {
            cout << "- ";
        }
    }
}