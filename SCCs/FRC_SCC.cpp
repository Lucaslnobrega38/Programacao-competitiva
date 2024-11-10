#include <bits/stdc++.h>
using namespace std;

int id = 0;
vector<bool> visited;
vector<int> ordem;
vector<int> group;
vector<int> grep;

class grafo
{
public:
    int size;
    vector<int> *container;

    grafo(int arg)
    {
        size = arg;
        container = new vector<int>[size];
    }

    void add(int de,int para)
    {
        container[de].push_back(para);
    }

    void dfs1(int node)
    {
        visited[node] = true;

        for (int v : container[node])
        {
            if (!visited[v]) dfs1(v);
        }

        ordem.push_back(node);
    }

    void dfs2(int node)
    {
        visited[node] = true;
        group[node] = id;
        grep[id] = node;

        for (int v : container[node])
        {
            if (!visited[v]) dfs2(v);
        }
    }
};

int main()
{
    int n,m;
    cin >> n >> m;

    visited.resize(n,false);
    group.resize(n);
    grep.resize(n);

    grafo g(n);
    grafo rg(n);

    int a,b;
    for (int i=0;i<m;i++)
    {
        cin >> a >> b;
        g.add(a-1,b-1);
        rg.add(b-1,a-1);
    }

    for (int i=0;i<n;i++)
    {
        if (!visited[i]) g.dfs1(i);
    }

    reverse(ordem.begin(),ordem.end());
    visited.assign(n,false);

    for (int i : ordem)
    {

        if (!visited[i]) 
        {
            rg.dfs2(i);
            id++;
        }
    }
    //cout << ordem.size();

    if (id == 1)
    {
        cout << "YES";
    }
    else
    {
        
        cout << "NO\n";
        cout << grep[1]+1 << " " << grep[0]+1;
    }
}