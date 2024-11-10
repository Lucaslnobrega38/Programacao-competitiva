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
        sizet = 4*arg;
        tree.resize(sizet,0);
        lazy.resize(sizet,0);
    }

    void unlazy(int tl,int tr,int node)
    {
        if (lazy[node] == 0) return;

        tree[node] += lazy[node]*(tr-tl+1);

        if (tl != tr)
        {
            lazy[2*node+1] += lazy[node];
            lazy[2*node+2] += lazy[node];
        }

        lazy[node] = 0;
    }

    void buildaux(int tl,int tr,int node,vector<int> &v)
    {
        if (tl == tr)
        {
            tree[node] = v[tl];
            return;
        }

        int mid = (tl+tr) >> 1;

        buildaux(tl,mid,2*node+1,v);
        buildaux(mid+1,tr,2*node+2,v);

        tree[node] = tree[2*node+1] + tree[2*node+2];
    }

    void build(vector<int> &v)
    {
        buildaux(0,size-1,0,v);
    }

    void updateaux(int tl,int tr,int node,int l,int r,int val)
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

    long long queryaux(int tl,int tr,int node,int index)
    {
        unlazy(tl,tr,node);

        if (tl == tr)
        {
            return tree[node];
        }

        int mid = (tl+tr) >> 1;

        if (index <= mid)
        {
            return queryaux(tl,mid,2*node+1,index);
        }
        else
        {
            return queryaux(mid+1,tr,2*node+2,index);
        }
    }

    long long query(int index)
    {
        return queryaux(0,size-1,0,index);
    }
};

int main()
{
    int n,q;
    cin >> n >> q;

    vector<int> arr(n);

    for (int i=0;i<n;i++) cin >> arr[i];

    seg tree(n);
    tree.build(arr);

    int op,a,b,c;
    while (q--)
    {
        cin >> op;

        if (op == 1)
        {
            cin >> a >> b >> c;
            tree.update(--a,--b,c);
        }
        else
        {
            cin >> a;
            cout << tree.query(--a) << endl;
        }
    }
}