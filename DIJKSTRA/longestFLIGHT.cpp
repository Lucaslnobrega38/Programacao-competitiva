#include <bits/stdc++.h>
using namespace std;
#define par pair<int,int>


class grafo
{
public:
    int size;
    vector<par> *container;

    grafo(int arg)
    {
        size = arg;
        container = new vector<par>[size];
    }

    void add(int de,int para)
    {
        container[de].push_back({1,para});
    }

    void dij(int source = 1)
    {
        vector<int> dists(size,INT_MIN);
        vector<int> parents(size,0);
        dists[source] = 0;

        priority_queue<par> pq; // retorna o maior valor
        
        pq.push({0,source});

        par frente;

        while (!pq.empty())
        {
            frente = pq.top();
            pq.pop();

            if (frente.first < dists[frente.second]) continue;

            for (par v : container[frente.second])
            {
                if (dists[v.second] < dists[frente.second] + v.first)
                {

                    dists[v.second] = dists[frente.second] + v.first;
                    pq.push({dists[v.second],v.second});
                    parents[v.second] = frente.second;
                }
            }
        }
        
        if (dists[size-1] == INT_MIN)
        {
            cout << "IMPOSSIBLE";
            return;
        }

        cout << dists[size-1]+1 << "\n";
        vector<int> res;
        
        int temp = size-1;

        while (temp != 1)
        {
            res.push_back(temp);
            temp = parents[temp];
        }

        res.push_back(1);

        for (int i=dists[size-1];i>=0;i--)
        {
            cout << res[i] << " ";
        }
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

    meug.dij();
}