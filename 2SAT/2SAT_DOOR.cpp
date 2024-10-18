#include <bits/stdc++.h>
using namespace std;

vector<int> ordem;
vector<int> comp;
int id = 0;
int ts;

class grafo
{
public:

    int size;
    vector<int> *g;
    vector<int> *r;
    vector<bool> visited;
    
    grafo(int arg)
    {
        size = arg;
        ts = arg*2;
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
    int n,m;
    cin >> n >> m;

    ts = 2*m;
    bool istate[n];
    vector<vector<int>> pswitches(n,vector<int>());

    for (int i=0;i<n;i++)  cin >> istate[i];

    int xi,temp;
    for (int i=0;i<m;i++)
    {
        cin >> xi;

        while (xi--)
        {
            cin >> temp;
            temp--;
            pswitches[temp].push_back(i);
        }
    }

    grafo meug(m);

    int first,second;
    int firstinv,secondinv;
    bool estadoi;
    for (int i=0;i<n;i++)
    {
        first = pswitches[i][0];
        second = pswitches[i][1];
        estadoi = istate[i];

        firstinv = first+m;
        secondinv = second+m;
        
        if (!estadoi)
        {
            meug.add(first,secondinv);
            meug.add(secondinv,first);

            meug.add(firstinv,second);
            meug.add(second,firstinv);

        }
        else
        {
            meug.add(first,second);
            meug.add(second,first);

            meug.add(firstinv,secondinv);
            meug.add(secondinv,firstinv);
        }

    }

    for (int i=0;i<ts;i++)
    {
        if (!meug.visited[i]) meug.dfs1(i);
    }

    reverse(ordem.begin(),ordem.end());
    meug.visited.assign(ts,false);

    for (int o : ordem)
    {
        if (!meug.visited[o]) {meug.dfs2(o);id++;}
    }

    for (int i=0;i<m;i++)
    {
        if (comp[i] == comp[i+m])
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

}