#include <bits/stdc++.h>
using namespace std;

int tsp(vector<vector<int>> dists, int bitmask,int origem)
{

    // D C B A
    // 3 2 1 0

    int n = dists.size();

    if (bitmask == (1<<n)-1)
    {
        return dists[origem][0];
    }

    int res = INT_MAX;

    for (int i=0;i<n;i++)
    {
        if ((bitmask & (1<<i)) == 0)
        {
            int loc = dists[origem][i] + tsp(dists,bitmask|(1<<i),i);
            res = min(res,loc);
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> dists =
    {
        {0,20,42,25},
        {20,0,30,34},
        {42,30,0,10},
        {25,34,10,0}
    };

    cout << tsp(dists,1,0);

}