#include <bits/stdc++.h>
using namespace std;
#define par pair<long long,int>

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

    void add(int de,int para,long long dist)
    {
        container[de].push_back({dist,para});
    }

    void dij(int source = 0)
    {
        //priority_queue<par,vector<par>,greater<par>> pq;
        set<par> pq;
        vector<long long> dists(size,LONG_LONG_MAX);

        //pq.push({0,source});
        pq.insert({0,source});
        dists[source] = 0;

        par frente;

        while (!pq.empty())
        {
            //frente = pq.top();
            frente = *pq.begin();
            //pq.pop();
            pq.erase(pq.begin());


            for (par viz : container[frente.second])
            {
                if (frente.first + viz.first < dists[viz.second])
                {
                    auto search = pq.find({dists[viz.second],viz.second});

                    if (search != pq.end()) pq.erase(search);


                    dists[viz.second] = frente.first+viz.first;

                    //pq.push({dists[viz.second],viz.second});
                    pq.insert({dists[viz.second],viz.second});
                }
            }
        }

        for (long long i : dists){cout << i << " ";}
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;
    grafo meug(n);

    int a,b;
    long long c;

    for (int i=0;i<m;i++)
    {
        cin >> a >> b >> c;
        meug.add(--a,--b,c);
    }

    meug.dij();
}