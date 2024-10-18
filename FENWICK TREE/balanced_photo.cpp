#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

class fenwick
{
public:

    int size;
    vector<int> arr;

    fenwick(int arg)
    {
        size = arg+1;
        arr.resize(size,0);
    }

    void update(int index,int val)
    {
        while (index < size)
        {
            arr[index] += val;
            index += (index & -index);
        }
    }

    ll sum(int r)
    {
        ll ans = 0;

        while (r > 0)
        {
            ans += (ll)arr[r];
            r -= (r & -r);
        }

        return ans;
    }

    ll sum(int l,int r)
    {
        return sum(r)-sum(l-1);
    }

};

int main()
{
    freopen("bphoto.in","r",stdin);
    freopen("bphoto.out","w",stdout);

    int n;
    cin >> n;

    vector<pair<int,int>> v_i(n+1);
    int temp;
    ll res = 0;

    v_i[0] = {-1,-1}; // valor a não ser usado. sempre estará em v_i[0].
    for (int i=1;i<=n;i++)
    {
        cin >> v_i[i].first;
        v_i[i].second = i;
    }

    sort(v_i.begin(),v_i.end());
    fenwick tree(n);

    ll r,l;

    for (int i=n;i>0;i--)
    {
        tree.update(v_i[i].second,1);

        r = tree.sum(v_i[i].second+1,n);
        l = tree.sum(1,v_i[i].second-1);

        if (r == l) continue;

        if (r < l) swap(r,l); // r sempre maior

        if (l == 0){res++;}
        else
        {
            if ((double(r) / double(l)) > 2) res++;
        }
    }

    cout << res;

}