#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class seg
{
public:
    int size;
    int sizet;
    vector<int> tree;

    seg(int arg)
    {
        size = arg;
        sizet = arg*4;
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

        tree[node] = tree[2*node+1]^tree[2*node+2];
    }

    void build(vector<int> &v)
    {
        buildaux(0,size-1,0,v);
    }

    int queryaux(int tl,int tr,int node,int l,int r)
    {
        if (tl > r or tr < l) return 0;

        if (tl >= l and tr <= r) return tree[node];

        int mid = (tl+tr) >> 1;

        return queryaux(tl,mid,2*node+1,l,r)^queryaux(mid+1,tr,2*node+2,l,r);
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

    vector<int> arr(n);

    for (int i=0;i<n;i++) cin >> arr[i];

    seg tree(n);
    tree.build(arr);

    int a,b;
    while (q--)
    {
        cin >> a >> b;

        cout << tree.query(--a,--b) << endl;
    }
}