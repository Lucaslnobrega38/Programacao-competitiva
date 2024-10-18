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
    vector<int> comp;
    //vector<int> compsize;
    vector<bool> visited;

    grafo(int arg)
    {
        size = arg;
        ts = arg*2;
        g = new vector<int>[ts];
        r = new vector<int>[ts];
        comp.resize(ts);
        //compsize.resize(ts,0);
        visited.resize(ts,false);
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
        //compsize[id]++;

        for (int v : r[node])
            if (!visited[v]) dfs2(v);
    }
};

int main()
{
    int n,r,k;
    cin >> n >> r >> k;

    vector<vector<pair<int,int>>> rows(n,vector<pair<int,int>>());
    vector<vector<pair<int,int>>> cols(n,vector<pair<int,int>>());
    vector<pair<int,int>> lamps;
    grafo meug(k);

    int linha,coluna;
    for (int i=0;i<k;i++)
    {
        cin >> linha >> coluna;
        linha--; coluna--;

        lamps.push_back({linha,coluna});
        rows[linha].push_back({coluna,i});
        cols[coluna].push_back({linha,i});

        sort(rows[linha].begin(),rows[linha].end());
        sort(cols[coluna].begin(),cols[coluna].end());
    }

    // a 1 2 1 b

    int linha2;
    int coluna2;
    int dist;
    pair<int,int> l1;
    pair<int,int> l2;

    for (int i=0;i<k;i++)
    {
        l1 = lamps[i];
        linha = l1.first;
        coluna = l1.second;

        for (int j=0;j<rows[linha].size();j++)
        {
            l2 = rows[linha][j];

            if (i==l2.second) continue;

            coluna2 = l2.first;

            dist = abs(coluna-coluna2);

            if (dist <= (r*2))
            {
                //cout << i << "colisaoh" << l2.second << "\n";
                meug.add(i,l2.second+k);
                meug.add(l2.second,i+k);
            }
        }

        for (int j=0;j<cols[coluna].size();j++)
        {
            l2 = cols[coluna][j];

            if (i == l2.second) continue;

            linha2 = l2.first;

            dist = abs(linha-linha2);

            if (dist <= (r*2))
            {
                //cout << i << "colisaov" << l2.second << "\n";
                meug.add(i+k,l2.second);
                meug.add(l2.second+k,i);
            }
        }
    }

    for (int i=0;i<meug.ts;i++)
    {
        if (!meug.visited[i]) meug.dfs1(i);
    }

    reverse(ordem.begin(),ordem.end());
    meug.visited.assign(meug.ts,false);

    for (int o : ordem)
    {
        if (!meug.visited[o])
        {
            meug.dfs2(o);
            id++;
        }
    }

    for (int i=0;i<k;i++)
    {
        if (meug.comp[i] == meug.comp[i+k])
        {
            cout << 0;
            return 0;
        }
    }

    cout << 1;
}