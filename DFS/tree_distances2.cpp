#include <bits/stdc++.h>
using namespace std;


class grafo
{
public:

    int size;
    vector<int> *container;
    vector<int> subsize;
    vector<long long> dists;

    grafo(int arg)
    {
        size = arg;
        container = new vector<int>[size];
        subsize = vector<int>(size,-1);
        dists = vector<long long>(size,0);
    }

    void add(int de,int para)
    {
        container[de].push_back(para);
        container[para].push_back(de);
    }

    void dfsaux(bool *visited,int node,int depth)
    {
        visited[node] = true;
        subsize[node] = 1;
        dists[0] += depth;

        for (int viz : container[node])
        {
            if (!visited[viz])
            {
                dfsaux(visited,viz,depth+1);

                subsize[node] += subsize[viz];
            }
        }
    }

    void dfs(int source)
    {
        bool visited[size]{false};
        dfsaux(visited,source,0);
    }

    void dfsaux2(bool *visited,int node,long long pdist,int parent)
    {
        visited[node] = true;

        if (parent != -1){
            dists[node] += pdist-(subsize[node])+(size-subsize[node]);

        }

        for (int viz : container[node])
        {
            if (!visited[viz])
            {
                dfsaux2(visited,viz,dists[node],node);
            }
        }
    }

    void dfs2(int source)
    {
        bool visited[size]{false};
        dfsaux2(visited,source,dists[source],-1);
    }

};

int main()
{
    int n;
    cin >> n;
    grafo meug(n);

    for (int i=0;i<n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        meug.add(a-1,b-1);
    }
    meug.dfs(0);
    meug.dfs2(0);
    
    for (auto x : meug.dists)
    {
        cout << x << " ";
    }

    
}