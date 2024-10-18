#include <bits/stdc++.h>
using namespace std;

int n,m,c,k;

class grafo
{
public:

    int size;
    list< pair<int,int> > *container; // {dist,ID}

    grafo(int arg)
    {
        size = arg;
        container = new list< pair<int,int> >[size];
    }

    void add(int de,int para,int dist)
    {
        container[de].push_back({dist,para});
        container[para].push_back({dist,de});
    }

    void dijkshtra(int source, int destiny)
    {
        set< pair<int,int> > meuset; // {dist,ID}
        vector<int> dists(size,INT_MAX);

        dists[source] = 0;
        meuset.insert({0,source});

        while(!meuset.empty())
        {
            auto it = meuset.begin();
            int frentedist = it->first;
            int frenteID = it->second;
            meuset.erase(it);

            for (auto viz : container[frenteID])
            {
                int vizID = viz.second;
                int vizdist = viz.first;

                if ((frenteID <= destiny)&&(abs(vizID-frenteID) > 1)){continue;}


                if (dists[vizID] > vizdist+frentedist)
                {

                    auto check = meuset.find({dists[vizID],vizID});

                    if (check != meuset.end()) meuset.erase(check);

                    dists[vizID] = vizdist+frentedist;
                    meuset.insert({dists[vizID],vizID});
                }
            }
        }
        cout << dists[destiny];
    }
};

int main()
{
    while(1)
    {
        cin >> n >> m >> c >> k;

        if (n+m+c+k == 0){return 0;}
        grafo meug(n);
        for (int i=0;i<m;i++)
        {
            int a,b,dist;
            cin >> a >> b >> dist;

            meug.add(a,b,dist);
        }

        meug.dijkshtra(k,c-1);
    }
}