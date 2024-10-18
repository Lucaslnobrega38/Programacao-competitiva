#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long

class fenwick
{
public:

    int size;
    vector<ll> arr;

    fenwick(int arg)
    {
        size = arg+1;
        arr.resize(size,0);
    }

    void update(int index,ll val)
    {
        while (index < size)
        {
            arr[index] += val;
            index += (index & -index);
        }
    }

    long long sum(int r)
    {
        long long ans = 0;

        while (r > 0)
        {   
            ans += arr[r];
            r -= (r & -r);
        }

        return ans;
    }

    long long sum(int l,int r)
    {
        return sum(r)-sum(l-1);
    }
};

int main()
{
    int n,q;
    cin >> n >> q;
    
    vector<ll> arr(n+1,0);
    fenwick tree(n);

    for (int i=1;i<=n;i++)
    {
        cin >> arr[i];
        tree.update(i,arr[i]-arr[i-1]);
    }


    int op;
    int k;
    long long a,b,v;
    while (q--)
    {
        cin >> op;

        if (op == 2)
        {
            cin >> k;
            cout << tree.sum(1,k) << endl;
        }
        else
        {
            cin >> a >> b >> v;

            tree.update(a,v);
            tree.update(b+1,-v);
        }

    }

}