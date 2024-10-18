#include <bits/stdc++.h>
using namespace std;

class grafo
{
    int size;
    list< pair<int,int> > *container;

public:

    grafo(int arg)
    {
        size = arg;
        container = new list< pair<int,int> >[arg];
    }

    void adiciona(int de, int para,int dist,bool undir = true)
    {
        container[de].push_back({dist,para});

        if (undir) container[para].push_back({dist,de});
    }

    void dij(int de,int para)
    {
        vector<int> distancias_finais(size,INT_MAX);
        set< pair<int,int> > meuset;

        meuset.insert({0,de});
        distancias_finais[de] = 0;

        while (!meuset.empty())
        {
            auto it = meuset.begin();
            int parcdist = it->first;
            int pontoa = it->second;
            meuset.erase(it);

            for (auto viz : container[pontoa])
            {
                int dvertex = viz.first;
                int dest = viz.second;

                if (parcdist + dvertex < distancias_finais[dest])
                {
                    auto check = meuset.find({distancias_finais[dest],dest});
                    if (check != meuset.end())  meuset.erase(check);
                    


                    distancias_finais[dest] = parcdist+dvertex;
                    meuset.insert({distancias_finais[dest], dest});
                }

            }

        }

        for (auto x : distancias_finais)
        {
            cout << x << " ";
        }
    }

};


int main()
{
    grafo meug(5);
    meug.adiciona(0,1,1);
    meug.adiciona(0,3,7);
    meug.adiciona(0,2,4);
    meug.adiciona(3,4,3);
    meug.adiciona(1,2,1);
    meug.adiciona(2,3,2);

    meug.dij(0,1);
}