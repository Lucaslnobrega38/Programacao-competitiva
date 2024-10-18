#include <bits/stdc++.h>
using namespace std;

#define p array<int,4>


class grafo
{
public:
    int size;
    vector<p> *container;

    grafo(int arg)
    {
        size = arg;
        container = new vector<p>[size];
    }

    void add(int de,int para,int dist,int flow)
    {
        container[de].push_back({0,dist,para,flow});
        container[para].push_back({0,dist,de,flow});
    }

    vector<int> dij(int source = 0)
    {
        priority_queue<p,vector<p>,less<p>> pq;

        pq.push({0,0,0,INT_MAX}); // rel,dist,node,flow
        vector<int> rels(size,0);

        int frel,fdist,fnode,fflow;
        int vrel,vdist,vnode,vflow;

        int newflow;
        int newrel;
        while (!pq.empty())
        {
            frel = pq.top()[0];
            fdist = pq.top()[1];
            fnode = pq.top()[2];
            fflow = pq.top()[3];

            pq.pop();
            for (auto v : container[fnode])
            {
                vrel = v[0];
                vdist = v[1];
                vnode = v[2];
                vflow = v[3];

                newflow = min(vflow,fflow);
                newrel = (newflow*1000000)/(vdist+fdist);
                if (newrel > rels[vnode])
                {
                    pq.push({newrel,vdist+fdist,vnode,newflow});
                    rels[vnode] = newrel;
                }   
            }
        }
        return rels;
    }
};

int main()
{
    freopen("pump.in","r",stdin);
    freopen("pump.out","w",stdout);

    int n,m;
    cin >> n >> m;

    grafo meug(n);

    int a,b,c,f;
    for (int i=0;i<m;i++)
    {
        cin >> a >> b >> c >> f;
        meug.add(a-1,b-1,c,f);
    }

    int res = meug.dij()[n-1];
    cout << res;
}