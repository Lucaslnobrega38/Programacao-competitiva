#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define lli pair<long long,int>

class grafo
{
public:
    int size;
    vector<lli> *container;
    vector<ll> dists;

    grafo(int arg)
    {
        size = arg;
        container = new vector<lli>[size];
        dists = vector<ll>(size,LONG_LONG_MAX);
    }

    void add(int de,int para,ll dist)
    {
        container[de].push_back({dist,para});
        container[para].push_back({dist,de});
    }

    void dij(int source = 0)
    {
        dists[source] = 0;
        priority_queue<lli,vector<lli>,greater<lli>> pq;
        pq.push({0,source});
        
        ll fdist;
        int fnode;

        ll vdist;
        int vnode;

        ll edist;
        int enode;

        ll tres;

        while (!pq.empty())
        {
            fdist = pq.top().first;
            fnode = pq.top().second;
            pq.pop();

            for (lli viz : container[fnode])
            {
                vdist = viz.first;
                vnode = viz.second;

                for (lli end : container[vnode])
                {
                    edist = end.first;
                    enode = end.second;

                    tres = ((edist+vdist)*(edist+vdist)) + fdist;

                    if (tres < dists[enode])
                    {
                        dists[enode] = tres;
                        pq.push({tres,enode});
                    }
                }
            }   

        }

        for (int i=0;i<size;i++)
        {
            if (dists[i] == LONG_LONG_MAX) dists[i] = -1;
        }
    }
};

int main()
{
    int n,m;
    cin >> n >> m;

    int a,b;
    ll c;

    grafo meug(n);

    for (int i=0;i<m;i++)
    {
        cin >> a >> b >> c;
        meug.add(a-1,b-1,c);
    }

    meug.dij();

    for (auto x : meug.dists)
    {
        cout << x << " ";
    }
}