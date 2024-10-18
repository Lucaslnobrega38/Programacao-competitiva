#include <bits/stdc++.h>
using namespace std;

int n,m,a,b,cdist;

class grafo
{
public:
    int size;
    list< pair<long,int> > *container; //dist,ID

    grafo(int arg)
    {
        size = arg;
        container = new list<pair<long,int>>[size];
    }

    void add(int de,int para,long dist)
    {
        container[de].push_back({dist,para});
    }

    vector<long long> dij(int source = 0, int destiny = n-1)
    {
        set< pair<long long,int> > meuset; // dist,ID
        vector<long long> dists(size,LONG_LONG_MAX);
        vector<long long> max_idist(size,-1);

        meuset.insert({0,source});
        dists[source] = 0;
        max_idist[source] = 0;
        

        while (!meuset.empty())
        {
            auto it = meuset.begin();

            long long frentedist = it->first;
            int frenteID = it->second;

            meuset.erase(it);

            for (auto viz : container[frenteID])
            {
                long long vizdist = viz.first;
                int vizID = viz.second;

                if (dists[vizID] > vizdist + frentedist)
                {
                    auto check = meuset.find({dists[vizID],vizID});

                    if (check != meuset.end()) meuset.erase(check);

                    dists[vizID] = vizdist+frentedist;
                    max_idist[vizID] = max(vizdist,max_idist[frenteID]);
                    meuset.insert({dists[vizID],vizID});
                }
            }
        }
        return dists;
    }
};

int main()
{
    cin >> n >> m;

    grafo meug(n);
    grafo meugrev(n);

    for (int i=0;i<m;i++)
    {
        cin >> a >> b >> cdist;

        meug.add(a-1,b-1,cdist);
        meugrev.add(b-1,a-1,cdist);
    }

    vector<long long> dists = meug.dij();
    vector<long long> distsrev = meugrev.dij(n-1,0);

    long long res=LONG_LONG_MAX;

    for (int i=0;i<n;i++)
    {
        for  (auto viz : meug.container[i])
        {
            if (dists[i] != LONG_LONG_MAX && distsrev[viz.second] != LONG_LONG_MAX)

            res = min(res, dists[i] + distsrev[viz.second] + viz.first/2);

        }
    }

    cout << res;
}