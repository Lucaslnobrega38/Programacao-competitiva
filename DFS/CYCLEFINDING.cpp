#include <bits/stdc++.h>
using namespace std;

class grafo
{
public:
    int size;
    vector<int> *container;
    vector<int> parents;
    vector<int> visited;

    grafo(int arg)
    {
        size = arg;
        container = new vector<int>[size];
        parents.resize(size,0);
        visited.resize(size,0);
    }

    void add(int de,int para)
    {
        container[de].push_back(para);
    }

    bool dfsaux(int node,int par)
    {
        visited[node] = 1; // ativo
        parents[node] = par;

        for (int v : container[node])
        {
            if (visited[v] == 0)
            {
                if (dfsaux(v,node)) return true;
            }
            else if (visited[v] == 1)
            {
                vector<int> res;
                int temp = node;
                
                while (temp != v)
                {
                    res.push_back(temp);
                    temp = parents[temp];
                }

                res.push_back(v);
                res.push_back(node);

                int s = res.size();

                cout << s << "\n";
                for (int i=s-1;i>=0;i--)
                    cout << res[i] << " ";

                return true;

            }
        }

        visited[node] = 2;
        return false;
    }

    bool dfs(int source)
    {
        return dfsaux(source,source);
    }

};

int main()
{
    int n,m;
    cin >> n >> m;

    grafo meug(n+1);

    int a,b;
    for (int i=0;i<m;i++)
    {
        cin >> a >> b;
        meug.add(a,b);
    }

    for (int i=1;i<=n;i++)
    {
        if (meug.visited[i] != 0) continue;

        if (meug.dfs(i)) return 0;
    }

    cout << "IMPOSSIBLE";
}