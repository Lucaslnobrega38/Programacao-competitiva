#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class seg
{
public:
    int size;
    int sizet;
    vector<int> tree;
    //vector<int> lazy;

    seg(int arg)
    {
        size = arg;
        sizet = 4*arg;
        tree.resize(sizet,0);
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

        tree[node] = min(tree[2*node+1],tree[2*node+2]);
    }

    void build(vector<int> &v)
    {
        buildaux(0,size-1,0,v);
    }

    int queryaux(int tl,int tr,int node,int l,int r)
    {
        if (tl > r or tr < l) return INT_MAX;

        if (tl >= l and tr <= r) return tree[node];

        int mid = (tl+tr) >> 1;

        return min(queryaux(tl,mid,2*node+1,l,r),queryaux(mid+1,tr,2*node+2,l,r));
    }

    int query(int l,int r)
    {
        return queryaux(0,size-1,0,l,r);
    }
};

int main()
{
    int n,q;
    cin >> n >> q;

    vector<int> v(n);

    for (int i=0;i<n;i++) cin >> v[i];

    seg tree(n);
    tree.build(v);

    int a,b;

    while (q--)
    {
        cin >> a >> b;
        cout << tree.query(--a,--b) << endl;
    }
}