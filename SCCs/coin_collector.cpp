#include <bits/stdc++.h>
using namespace std;

vector<int> ordem;
vector<pair<int,int>> edges;
long long dp[100000];

class grafo
{
public:
    int size;
    vector<int> *g;
    vector<int> *r;
    vector<bool> visited;
    vector<int> comp;
    vector<long long> compsum;
    vector<int> *container;
    int id = 0;

    grafo(int arg)
    {
        size = arg;
        g = new vector<int>[size];
        r = new vector<int>[size];
        visited.resize(size,false);
        comp.resize(size);
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

    void gen()
    {
        container = new vector<int>[id];

        for (pair<int,int> e : edges)
        {
            if (comp[e.first] == comp[e.second]) continue;

            container[comp[e.second]].push_back(comp[e.first]);
            // reverso
        }
    }

    long long trav(int node)
    {
        if (dp[node] != 0) return dp[node];
        
        dp[node] = compsum[node];

        for (int p : container[node])
        {
            dp[node] = max(dp[node],trav(p)+compsum[node]);
        }

        return dp[node];
    }
};

int main()
{
    
    int n,m;
    cin >> n >> m;

    memset(dp,0,sizeof(dp));

    grafo meug(n);
    edges.resize(m,pair<int,int>());
    
    int coins[n];

    for (int i=0;i<n;i++) cin >> coins[i];

    int a,b;
    for (int i=0;i<m;i++)
    {
        cin >> a >> b;
        a--,b--;
        meug.add(a,b);
        edges[i] = {a,b};
    }


    for (int i=0;i<n;i++)
        if (!meug.visited[i]) meug.dfs1(i);



    reverse(ordem.begin(),ordem.end());
    meug.visited.assign(n,false);

    
    for (int o : ordem)
    {
        if (!meug.visited[o])
        {
            meug.dfs2(o);
            meug.id++;
        }
    }   

    meug.compsum.resize(meug.id,0);
    for (int i=0;i<n;i++)
    {
        meug.compsum[meug.comp[i]] += coins[i];
    }

    //for (int i=0;i<meug.id;i++) cout << meug.compsum[i] << " ";
    meug.gen();

    long long res = 0;

    for(int i=0;i<meug.id;i++)
    {
        res = max(res,meug.trav(i));
    }

    cout << res;
}