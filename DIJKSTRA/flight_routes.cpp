#include <bits/stdc++.h>
using namespace std;

#define pairli pair<long long,int>
int k;

class grafo
{
public:

    int size;
    vector<pairli> *container;
    vector<vector<long long>> dists;

    grafo(int arg)
    {
        size = arg;
        container = new vector<pairli>[size];
        dists = vector<vector<long long>>(size,vector<long long>(k,LONG_LONG_MAX));
    }

    void add(int de,int para,long long dist)
    {
        container[de].push_back({dist,para});
    }

    void dij(int source)
    {
        priority_queue<pairli,vector<pairli>,greater<pairli>> pq;
        dists[source][k-1] = 0;
        sort(dists[source].begin(),dists[source].end());

        pq.push({0,source});

        while(!pq.empty())
        {
            long long fdist = pq.top().first;
            int fnode = pq.top().second;
            pq.pop();
            if (fdist > dists[fnode][k-1]) continue;

            
            for (auto v : container[fnode])
            {
                long long vdist = v.first;
                int vnode = v.second;

                if (vdist+fdist < dists[vnode][k-1])
                {
                    dists[vnode][k-1] = vdist+fdist;
                    sort(dists[vnode].begin(),dists[vnode].end());
                    pq.push({vdist+fdist,vnode});
                }
            }
        }
    }
};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.sync_with_stdio(false);

    int n,m;
    cin >> n >> m >> k;

    grafo meug(n);

    int a,b;
    long long c;
    for (int i=0;i<m;i++)
    {
        cin >> a >> b >> c;
        meug.add(a-1,b-1,c);
    }

    meug.dij(0);
    for (auto x : meug.dists[n-1])
    {
        cout << x << " ";
    }
}