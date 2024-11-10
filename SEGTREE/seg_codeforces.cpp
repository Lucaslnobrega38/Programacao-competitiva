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
        sizet = 4*arg;
        tree.resize(sizet,0);
        lazy.resize(sizet,-1);
    }

    void unlazy(int tl,int tr,int node)
    {
        if (lazy[node] == -1) return;

        tree[node] = lazy[node];

        if (tl != tr)
        {
            lazy[2*node+1] = lazy[node];
            lazy[2*node+2] = lazy[node];
        }

        lazy[node] = -1;
    }

    void updateaux(int tl,int tr,int node,int l,int r, int val)
    {
        unlazy(tl,tr,node);

        if (tl > r or tr < l) return;

        if (tl >= l and tr <= r)
        {
            lazy[node] = val;
            unlazy(tl,tr,node);
            return;
        }

        int mid = (tl+tr) >> 1;

        updateaux(tl,mid,2*node+1,l,r,val);
        updateaux(mid+1,tr,2*node+2,l,r,val);
    }

    void update(int l,int r,int val)
    {
        updateaux(0,size-1,0,l,r,val);
    }

    int queryaux(int tl,int tr,int node,int index)
    {
        unlazy(tl,tr,node);

        if (tl == tr) return tree[node];

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

    int query(int index)
    {
        return queryaux(0,size-1,0,index);
    }
};

int main()
{
    int n,m;
    cin >> n >> m;

    seg tree(n);

    int op,a,b,c;

    while (m--)
    {
        cin >> op;

        if (op == 2)
        {
            cin >> a;
            cout << tree.query(a) << endl;
        }
        else
        {
            cin >> a >> b >> c;
            tree.update(a,--b,c);
        }
    }
}