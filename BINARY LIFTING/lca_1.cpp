#include <bits/stdc++.h>
using namespace std;

class grafo
{
public:
    int size;
    vector<int> *container;
    vector<int> profs;
    vector<int> prevs;

    grafo(int arg)
    {
        size = arg;
        container = new vector<int>[size];
        profs = vector<int>(size,-1); 
        prevs = vector<int>(size,-1);
    }

    void add(int de, int para)
    {
        container[de].push_back(para);
    }

    void dfsaux(bool *visited,int node,int depth,int parent)
    {
        visited[node] = true;
        profs[node] = depth;
        prevs[node] = parent;

        for (auto viz : container[node])
        {
            if (!visited[viz])
            {
                dfsaux(visited,viz,depth+1,node);
            }
        }
    }

    void dfs(int source)
    {
        bool visited[size]{false};
        dfsaux(visited,0,0,-1);
    }

    void lca(int a, int b)
    {
        int pa = a;
        int pb = b;

        int da = profs[a];
        int db = profs[b];

        if (da > db)
        {
            while (da > db)
            {
                da--;
                pa = prevs[pa];
            }
        }
        else
        {
            while (db > da)
            {
                db--;
                pb = prevs[pb];
            }
        }

        while (da >= 0)
        {
            if (pa == pb)
            {
                cout << pa+1 << endl;
                return;
            }

            da--;
            pa = prevs[pa];
            pb = prevs[pb];

        }

    }
};

int main()
{
    int t;
    cin >> t;for (int a=0;a<t;a++){
    cout << "Case " << a+1 << ":\n";
    
    int n;
    cin >> n;

    grafo meug(n);

    for (int i=0;i<n;i++)
    {
        int qt;
        cin >> qt;

        for (int j=0;j<qt;j++)
        {
            int temp;
            cin >> temp;
            meug.add(i,temp-1);
        }
    }

    int q;
    cin >> q;

    meug.dfs(0);

    for (int i=0;i<q;i++)
    {
        int a,b;
        cin >> a >> b;
        meug.lca(a-1,b-1);
    }


}}