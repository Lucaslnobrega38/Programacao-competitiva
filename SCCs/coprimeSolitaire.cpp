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
    vector<bool> visited;
    vector<int> comp;

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
            if (!visited[v]) dfs1(v);

        ordem.push_back(node);
    }

    void dfs2(int node)
    {
        visited[node] = true;
        comp[node] = id;

        for (int v : r[node])  
            if (!visited[v]) dfs2(v);
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    grafo meug(n);
    pair<int,int> arr[n];

    for (int i=0;i<n;i++)
    {
        cin >> arr[i].first;
        cin >> arr[i].second;
    }

    pair <int,int> pi,pj;

    for (int i=0;i<n;i++)
    for (int j=i+1;j<n;j++)
    {
        pi = arr[i];
        pj = arr[j];

        if (__gcd(pi.first,pj.first) != 1)
        {
            meug.add(i,j+n);
            meug.add(j,i+n);
        }

        if (__gcd(pi.first,pj.second) != 1)
        {
            meug.add(i,j);
            meug.add(j+n,i+n);
        }

        if (__gcd(pi.second,pj.first) != 1)
        {
            meug.add(i+n,j+n);
            meug.add(j,i);
        }

        if (__gcd(pi.second,pj.second) != 1)
        {
            meug.add(i+n,j);
            meug.add(j+n,i);
        }
    }

    for (int i=0;i<meug.ts;i++)
        if (!meug.visited[i]) meug.dfs1(i);

    meug.visited.assign(meug.ts,false);
    reverse(ordem.begin(),ordem.end());

    for (int o : ordem)
        if (!meug.visited[o])
        {
            meug.dfs2(o);
            id++;
        }
    
    for (int i=0;i<n;i++)
    {
        if (meug.comp[i] == meug.comp[i+n])
        {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";
    

}