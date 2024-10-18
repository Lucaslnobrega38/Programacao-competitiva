#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> res;
int k;

class grafo
{
public:

    int size;
    vector< pair<ll,int> > *container; //dist,id
    vector<vector<ll>> dists;


    grafo(int arg)
    {
        size = arg;
        container = new vector< pair<ll,int> >[size];
        //dists = vector<vector<ll>>(size,vector<ll>(size,LONG_LONG_MAX));

    }

    void add(int de,int para,ll dist)
    {
        container[de].push_back({dist,para});
    }

    void dij(int source,int dest)
    {
        multiset<pair<ll,int>> meuset;

        meuset.insert({0,source});
        

        int count = 0;

        while (!meuset.empty())
        {
            if (count > k+2){return;}

            auto it = meuset.begin();
            ll fdist = it->first;
            int fnode = it->second;
            meuset.erase(it);

            if (dists[fnode][k-1] < fdist) continue;

            for (auto v : container[fnode])
            {
                ll vdist = v.first;
                int vnode = v.second;

                if (dists[vnode][k-1] > vdist+fdist)
                {
                    dists[vnode][k-1] = vdist+fdist;
                    sort(dists[vnode].begin(),dists[vnode].end());
                    meuset.insert({vdist+fdist,vnode});
                    //cout << vdist << " " << fdist << endl;
                }
            }
        }
    }
};

int main()
{
    int n,m;
    cin >> n >> m >> k;

    grafo meug(n);
    meug.dists = vector<vector<ll>>(n,vector<ll>(k,LONG_LONG_MAX));


    int a,b;
    ll c;
    for (int i=0;i<m;i++)
    {
        cin >> a >> b >> c;
        meug.add(a-1,b-1,c);
    }

    meug.dij(0,n-1);

    for (int i=0;i<k;i++)
    {
        cout << meug.dists[n-1][i] << " ";
    }
}

