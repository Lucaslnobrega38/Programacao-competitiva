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

    void dij(int source = 1)
    {
        vector<long long> dists(size,LONG_LONG_MAX);
        dists[source] = 0;

        vector<int> num(size,0);
        num[source] = 1;

        vector<int> maxf(size,INT_MIN);
        maxf[source] = 0;

        vector<int> minf(size,INT_MAX);
        minf[source] = 0;

        priority_queue<par,vector<par>,greater<par>> pq;
        pq.push({0,source});

        par frente;

        while (!pq.empty())
        {
            frente = pq.top();
            pq.pop();

           if (frente.first > dists[frente.second]) continue;

            for (par v : container[frente.second])
            {
                if (dists[v.second] > frente.first + v.first)
                {
                    dists[v.second] = frente.first + v.first;

                    minf[v.second] = minf[frente.second]+1;
                    maxf[v.second] = maxf[frente.second]+1;
                    num[v.second] = num[frente.second];

                    pq.push({dists[v.second],v.second});
                    continue;
                }

                if (dists[v.second] == frente.first + v.first)
                {
                    minf[v.second] = min(minf[v.second],minf[frente.second]+1);
                    maxf[v.second] = max(maxf[v.second],maxf[frente.second]+1);
                    num[v.second] = (num[v.second]+num[frente.second])%1000000007;
                    //pq.push({dists[v.second],v.second});
                }
            }
        }

        cout << dists[size-1] << " " << num[size-1] << " "
        << minf[size-1] << " " << maxf[size-1];
    }

};

int main()  
{
    int n,m;
    cin >> n >> m;

    grafo meug(n+1);

    int a,b;
    long long c;
    while (m--)
    {
        cin >> a >> b >> c;
        meug.add(a,b,c);
    }

    meug.dij();


}