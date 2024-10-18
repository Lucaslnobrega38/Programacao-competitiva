#include <bits/stdc++.h>
using namespace std;

int ans = 0;
bool paired[200005]{false};

class grafo
{
public:
    int size;
    vector<int> *container;

    vector<int> pais_de_folhas;

    grafo(int arg)
    {
        size = arg;
        container = new vector<int>[size];
    }

    void add(int de, int para)
    {
        container[de].push_back(para);
        container[para].push_back(de);
    }

    void dfsaux(int node,int parent)
    {
        for (int viz : container[node])
        {
            if (viz != parent)
            {
                dfsaux(viz,node);

                if (!paired[viz] && !paired[node])
                {
                    paired[viz] = paired[node] = true;
                    ans++;
                }
            }
        }

       
    }

    void dfs(int source)
    {
        bool paired[size]{false};
        dfsaux(source,-1);
    }

    
};

int main()
{
    int n;
    cin >> n;

    grafo meug(n);

    int a,b;
    for (int i=0;i<n-1;i++)
    {
        cin >> a >> b;
        meug.add(a-1,b-1);
    }

    meug.dfs(0);

    cout << ans;


}