#include <bits/stdc++.h>
using namespace std;

class grafo
{
public:

    int size;
    list< pair<long long,int>> *container; // dist, ID

    grafo(int arg)
    {
        size = arg;
        container = new list< pair<long long, int>>[size];
    }

    void add(int de,int para, long long dist)
    {
        container[de].push_back({dist,para});
        container[para].push_back({dist,de});
    }

    void dij(int source)
    {
        set<pair< long long, int> > meuset;
        vector<long long> dists(size,LONG_LONG_MAX);

        meuset.insert({0,source});
        dists[source] = 0;

        while (!meuset.empty())
        {
            auto it = meuset.begin();
            
            long long frentedist = it->first;
            int frenteid = it->second;

            meuset.erase(it);

            for (auto viz : container[frenteid])
            {
                long long vizdist = viz.first;
                int vizid = viz.second;

                if (dists[vizid] > vizdist+frentedist)
                {
                    auto check = meuset.find({dists[vizid],vizid});

                    if (check != meuset.end()) meuset.erase(check);

                    dists[vizid] = frentedist + vizdist;

                    meuset.insert({dists[vizid],vizid});
                }

            }

        }

        sort(dists.begin(),dists.end());

        cout << (*(dists.end()-1)) - (*(dists.begin()+1));
    }
};


int main()
{
    int n,m;
    cin >> n >> m;

    grafo meug(n);

    for (int i=0;i<m;i++)
    {
        int a,b;
        long long dist;
        cin >> a >> b >> dist;

        meug.add(a-1,b-1,dist);
    }

    int s;
    cin >> s;

    meug.dij(s-1);
}