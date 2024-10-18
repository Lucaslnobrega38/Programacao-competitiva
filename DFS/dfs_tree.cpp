#include <bits/stdc++.h>
using namespace std;

int parents[200000];
int res[200000];

class grafo
{
public:
    int size;
    list<int> *container;

    grafo(int arg)
    {
        size = arg;
        container = new list<int>[size];
    }

    void add(int de, int para)
    {
        container[de].push_back(para);
    }

    void dfsaux(bool *visited, int node)
    {
        visited[node] = true;
       

        for (auto x : container[node])
        {
            if (!visited[x])
            {
                dfsaux(visited,x);
                res[node] += res[x]+1;                
            }
        }

        return;
    }

    void dfs(int source)
    {
        bool visited[size]{false};
        dfsaux(visited,source);
    }
};

int main()
{
    int n;
    cin >> n;

    grafo meug(n);

    for (int i=1;i<n;i++)
    {
        cin >> parents[i];
        parents[i]--;

        meug.add(parents[i],i);
    }

    meug.dfs(0);



    for (int i=0;i<n;i++) cout << res[i] << " ";
}