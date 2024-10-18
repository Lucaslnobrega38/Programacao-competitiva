#include <bits/stdc++.h>
using namespace std;

vector<int> ordem;
int id = 0;
int ts;

class grafo
{
public:
    int size;
    vector<int> *g;
    vector<int> *r;
    vector<bool> visited;
    vector<int> comp;

    grafo(int arg)
    {
        size = arg;

        g = new vector<int>[ts];
        r = new vector<int>[ts];

    
        visited.resize(ts,false);
        comp.resize(ts);
    }

    void add(int de,int para)
    {
        g[de].push_back(para);
        r[para].push_back(de);
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
    int t; cin >> t;
    for (int xtz = 1;xtz<=t;xtz++)
    {
    
    id = 0;
    ordem.clear();
    cout << "Scenario #" << xtz << ":\n";

    int bugs,inters;
    cin >> bugs >> inters;

    
    ts = bugs*2;
    grafo meug(bugs);
    

    int a,b;
    int inva,invb;
    for (int i=0;i<inters;i++)
    {
        cin >> a >> b;
        a--;
        b--;

        inva = a+bugs;
        invb = b+bugs;

        meug.add(a,invb);
        meug.add(invb,a);

        meug.add(b,inva);
        meug.add(inva,b);
        
    }

    for (int i=0;i<ts;i++)
    {
        if (!meug.visited[i]) meug.dfs1(i);
    }

    reverse(ordem.begin(),ordem.end());
    meug.visited.assign(ts,false);

    for (int o : ordem)
    {
        if (!meug.visited[o])
        {
            meug.dfs2(o);
            id++;
        }
    }

    bool found = false;

    for (int i=0;i<bugs;i++)
    {
        if (meug.comp[i] == meug.comp[i+bugs])
        {
            cout << "Suspicious bugs found!\n";
            found = true;
            break;
        }
    }

    if (found) continue;

    cout << "No suspicious bugs found!\n";
    
    }
    }
