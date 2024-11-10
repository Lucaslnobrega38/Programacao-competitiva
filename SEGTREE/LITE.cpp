#include <bits/stdc++.h>
using namespace std;
#define endl "\n"


class seg
{
public:
    int size;
    int sizet;
    vector<int> tree;
    vector<int> lazy;

    seg(int arg)
    {
        size = arg;
        sizet = arg*4;
        tree.resize(sizet,0);
        lazy.resize(sizet,0);
    }

    void unlazy(int tl,int tr,int node)
    {
        if ((lazy[node]%2) == 0) return;

        tree[node] = (tr-tl+1) - tree[node];

        if (tl != tr)
        {
            lazy[2*node+1]+=lazy[node];
            lazy[2*node+2]+=lazy[node];
        }

        lazy[node] = 0;
    }

    void updateaux(int tl,int tr,int node,int l,int r)
    {
        unlazy(tl,tr,node);

        if (tl > r or tr < l) return;

        if (tl >= l and tr <= r)
        {
            lazy[node]++;
            unlazy(tl,tr,node);
            return;
        }

        int mid = (tl+tr) >> 1;

        updateaux(tl,mid,2*node+1,l,r);
        updateaux(mid+1,tr,2*node+2,l,r);

        tree[node] = tree[2*node+1] + tree[2*node+2];

    }

    void update(int l,int r)
    {
        updateaux(0,size-1,0,l,r);
    }

    int queryaux(int tl,int tr,int node,int l,int r)
    {
        unlazy(tl,tr,node);

        if (tl > r or tr < l) return 0;

        if (tl >= l and tr <= r)
        {
            return tree[node];
        }

        int mid = (tl+tr) >> 1;

        return queryaux(tl,mid,2*node+1,l,r) + queryaux(mid+1,tr,2*node+2,l,r);
    }

    int query(int l,int r)
    {
        return queryaux(0,size-1,0,l,r);
    }
};

int main()
{
    int n,m;
    cin >> n >> m;

    seg tree(n);

    int a,b;
    bool op;
    while (m--)
    {
        cin >> op >> a >> b;

        if (!op)
        {
            tree.update(--a,--b);
        }
        else
        {
            cout << tree.query(--a,--b) << endl;
        }
    }
}