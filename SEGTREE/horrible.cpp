#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class seg
{
public:
    int size;
    int sizet;
    vector<long long> tree;
    vector<long long> lazy;
    
    seg(int arg)
    {
        size = arg;
        sizet = arg*4;
        tree.resize(sizet,0);
        lazy.resize(sizet,0);
    }

    void unlazy(int tl,int tr,int node)
    {
        if (lazy[node] == 0) return;

        tree[node] += lazy[node]*(tr-tl+1);

        if (tr!=tl)
        {
            lazy[2*node+1] += lazy[node];
            lazy[2*node+2] += lazy[node];
        }

        lazy[node] = 0;
    }

    void updateaux(int tl,int tr,int node,int l,int r,long long val)
    {
        unlazy(tl,tr,node);

        if (tl > r or tr < l) return;

        if (tl >= l and tr <= r)
        {
            lazy[node] += val;
            unlazy(tl,tr,node);
            return;
        }

        int mid = (tl+tr) >> 1;

        updateaux(tl,mid,2*node+1,l,r,val);
        updateaux(mid+1,tr,2*node+2,l,r,val);

        tree[node] = tree[2*node+1] + tree[2*node+2];
    }

    void update(int l,int r,int val)
    {
        updateaux(0,size-1,0,l,r,val);
    }

    long long queryaux(int tl,int tr,int node,int l,int r)
    {
        unlazy(tl,tr,node);

        if (tl > r or tr < l) return 0;

        if (tl >= l and tr <= r) return tree[node];

        int mid = (tl+tr) >> 1;

        return queryaux(tl,mid,2*node+1,l,r) + queryaux(mid+1,tr,2*node+2,l,r);

    }

    long long query(int l,int r)
    {
        return queryaux(0,size-1,0,l,r);
    }
};

int main()
{
    int t;
    cin >> t;

    int n, c;

    bool op;
    int a,b,d;
    while (t--)
    {
        cin >> n >> c;
        seg tree(n);

        while (c--)
        {
            cin >> op;

            if (op)
            {
                cin >> a >> b;
                cout << tree.query(--a,--b) << endl;
            }
            else
            {
                cin >> a >> b >> d;
                tree.update(--a,--b,d);
            }
        }
    }
}