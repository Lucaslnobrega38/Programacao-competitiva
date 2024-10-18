#include <bits/stdc++.h>
using namespace std;

int n,m,s,d;
int u,v;
long long p;
list< pair<long long,int> > lixo(1,{-1,-1});

class grafo
{
public:
    int size;
    list< pair<long long,int> > *container; //dist,ID

    grafo(int arg)
    {
        size = arg;
        container = new list<pair<long long,int>>[size];
    }

    void add(int de,int para,long long dist)
    {
        container[de].push_back({dist,para});
    }

    long long dij(int fonte,int destino)
    {
        
        set <pair<long long,int> > meuset; // dist,ID
        vector<long long> dists(size,LONG_LONG_MAX);
        vector< list< pair<long long,int> >::iterator > precedev(size, lixo.begin());
        vector<int> precede(size,-1);

        dists[fonte] = 0;
        precede[fonte] = -1;
        meuset.insert({dists[fonte],fonte});

        while (!meuset.empty())
        {
            auto it = meuset.begin();
            long long frentedist = it->first;
            int frenteid = it->second;
            meuset.erase(it);

            for (auto viz = container[frenteid].begin(); viz != container[frenteid].end(); viz++)
            {
                long long vizdist = (*viz).first;
                int vizid = (*viz).second;

                if (dists[vizid] > vizdist + frentedist)
                {
                    auto check = meuset.find({dists[vizid],vizid});
                    if (check != meuset.end()) meuset.erase(check);

                    dists[vizid] = vizdist + frentedist;
                    meuset.insert({dists[vizid],vizid});
                    precedev[vizid] = viz;
                    precede[vizid] = frenteid;
                }

            }
        }

        int temp = destino;
        while (temp != fonte)
        {
            //cout << temp<<"$";
            if (precedev[temp] == lixo.begin()) break;

            container[(*precedev[temp]).second].erase(precedev[temp]);



            temp = precede[temp];

            if (temp == -1){return -1;}
        }
        
        return dists[destino];
    }
}; 

int main()
{
    while (1)
    {
        cin >> n >> m;

        if (n+m == 0) return 0;

        cin >> s >> d;

        grafo meug(n);

        for (int i=0;i<m;i++)
        {
            cin >> u >> v >> p;
            meug.add(u,v,p);
        }

        int best = meug.dij(s,d);
        int res;
        while (1)
        {
            if (best != (res = meug.dij(s,d)))
            {
                cout << res;
                break;
            }
        }

    }
}