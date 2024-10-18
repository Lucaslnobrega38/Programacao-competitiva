#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define trio tuple<ll,int,int>
#define quarteto tuple<int,int,int,int>

quarteto bs(vector<trio> *pares,ll tgt)
{
    int ini = 0;
    int end = pares->size()-1;

    ll midsum;

    while (ini < end)
    {
        auto [p1,i,j] = (*pares)[ini];
        auto [p2,k,l] = (*pares)[end];

        midsum = p1+p2;

        if (midsum == tgt)
        {
            if (i != k && i != l && j != k && j != l)
                return make_tuple(i,j,k,l);

            if (get<0>((*pares)[end]) - get<0>((*pares)[end-1])< get<0>((*pares)[i+1])-get<0>((*pares)[i]))
            {
                end--;
                continue;
            }
            
            ini++;
        }

        if (midsum > tgt)
        {
            end--;
        }
        else
        {
            ini++;
        }
    }


    return make_tuple(-1,-1,-1,-1);
}

int main()
{
    int n;
    ll x;

    

    cin >> n >> x;

    ll arr[n];

    for (int i=0;i<n;i++) cin >> arr[i];

    vector<trio> pares;

    for (int i=0;i<n;i++)
    for (int j=i+1;j<n;j++)
    {
        pares.push_back({arr[i]+arr[j],i+1,j+1});
    }

    sort(pares.begin(),pares.end());

    auto [a,b,c,d] = bs(&pares,x);

    if (a != -1)
    {
        cout << a << " " << b << " " << c << " " << d;
        return 0;
    }

    cout << "IMPOSSIBLE";
}