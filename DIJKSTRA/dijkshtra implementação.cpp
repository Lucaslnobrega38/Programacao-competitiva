#include <bits/stdc++.h>
using namespace std;

class grafo
{
public:

    int size;
    bool mat[100][100];

    grafo(int arg)
    {
        size = arg;
    }

    void dijkshtra()
    {
        set<pair <int, pair<int,int> >> meuset;
        vector<vector<int>> dists(size,vector<int>(size,INT_MAX));
        pair<int,int> fonte = {0,0};
        meuset.insert({0,{0,0}});
        dists[0][0] = 0;

        while(!meuset.empty())
        {
            auto it = meuset.begin();
            int dist = it->first;
            pair <int,int> coord = it->second;
            meuset.erase(it);

            if (coord.first > 0)
            {
                if (dists[coord.first-1][coord.second] > dist + mat[coord.first-1][coord.second])
                {
                    auto check = meuset.find({dists[coord.first-1][coord.second],{coord.first-1,coord.second}});
                    if (check != meuset.end()) meuset.erase(check);
                    
                    dists[coord.first-1][coord.second] = dist + mat[coord.first-1][coord.second];
                    meuset.insert({dists[coord.first-1][coord.second],{coord.first-1,coord.second}});
                    
                }
            }

            if (coord.first < size-1)
            {
                if (dists[coord.first+1][coord.second] > dist + mat[coord.first+1][coord.second])
                {
                    auto check = meuset.find({dists[coord.first+1][coord.second],{coord.first+1,coord.second}});
                    if (check != meuset.end()) meuset.erase(check);
                    
                    dists[coord.first+1][coord.second] = dist + mat[coord.first+1][coord.second];
                    meuset.insert({dists[coord.first+1][coord.second],{coord.first+1,coord.second}});
                    
                }
            }

            if (coord.second > 0)
            {
                if (dists[coord.first][coord.second-1] > dist + mat[coord.first][coord.second-1])
                {
                    auto check = meuset.find({dists[coord.first][coord.second-1],{coord.first,coord.second-1}});
                    if (check != meuset.end()) meuset.erase(check);

                    dists[coord.first][coord.second-1] = mat[coord.first][coord.second-1] + dist;
                    meuset.insert({dists[coord.first][coord.second-1],{coord.first,coord.second-1}});

                }
            }

            if (coord.second < size-1)
            {
                if (dists[coord.first][coord.second+1] > dist + mat[coord.first][coord.second+1])
                {
                    auto check = meuset.find({dists[coord.first][coord.second+1],{coord.first,coord.second+1}});
                    if (check != meuset.end()) meuset.erase(check);

                    dists[coord.first][coord.second+1] = mat[coord.first][coord.second+1] + dist;
                    meuset.insert({dists[coord.first][coord.second+1],{coord.first,coord.second+1}});

                }
            }



        }
        cout << dists[size-1][size-1];
    }

};




int main()
{
    int n;
    cin >> n;
    grafo meug(n);

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            int temp;
            cin >> temp;
            meug.mat[i][j] = temp;
        }
    }

    meug.dijkshtra();



    
}