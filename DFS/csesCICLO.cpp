#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
 
vector<int> res;
bool visited[100001]{false};

 
class grafo
{
public:
 
    int size;
    vector<int> *container;
    vector<int> parents;
    

    grafo(int arg)
    {
        size = arg;
        container = new vector<int>[size];
        parents.resize(size);
    }
 
    void add(int de,int para)
    {
        container[de].push_back(para);
        container[para].push_back(de);
    }
 
    bool dfsaux(int node,int parent,bool *visited,int raiz)
    {
        visited[node] = true;
        parents[node] = parent;

        for (int v : container[node])
        {
            if (!visited[v])
            { 
                if (dfsaux(v,node,visited,raiz))
                    return true;
                
            }
            else
            {
                if (v != parent)
                {
                    int temp = node;

                    while (temp != v)
                    {
                        res.push_back(temp);
                        temp = parents[temp];

                    }
                    res.push_back(v);
                    res.push_back(node);
 
 
                    return true;
                }
            }
        }
 
        return false;
    }
 
    bool dfs(int source)
    {

        bool r;
        r = dfsaux(source,source,visited,source);
 
        if (r)
        {
            cout << res.size() << endl;
            for (auto x : res) cout << x << " ";
            return true;
        }
        return false;
    }
 
};
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
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
        if (visited[i]){continue;}

        if (meug.dfs(i))
        {
            return 0;
        }

    }
    cout << "IMPOSSIBLE";
}