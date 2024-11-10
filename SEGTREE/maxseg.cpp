#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define q array<long long,4>

// suf pref seg sum

class seg
{
public:
    int size;
    int sizet;
    vector<q> tree;
    vector<long long> lazy;

    seg(int arg)
    {
        size = arg;
        sizet = 4*arg;
        tree.resize(sizet,{0,0,0,0});
        lazy.resize(sizet,LONG_LONG_MAX);
    }

    void unlazy(int tl,int tr,int node)
    {
        if (lazy[node] == LONG_LONG_MAX) return;

        if (lazy[node] >= 0)
        {
            tree[node][0] = tree[node][1] =
            tree[node][2] = tree[node][3] = lazy[node]*(tr-tl+1);
  
        }
        else
        {
            tree[node][3] = lazy[node]*(tr-tl+1);
            tree[node][1] = tree[node][2] = tree[node][0] = 0;
        }

        if (tl != tr)
        {
            lazy[2*node+1] = lazy[node];
            lazy[2*node+2] = lazy[node];
        }

        lazy[node] = LONG_LONG_MAX;
    }

    void updateaux(int tl,int tr,int node,int l,int r,int val)
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

        // suf pref seg sum

        tree[node][0] = max(tree[2*node+2][0],tree[2*node+2][3]+tree[2*node+1][0]);
        tree[node][1] = max(tree[2*node+1][1],tree[2*node+1][3]+tree[2*node+2][1]);

        tree[node][2] = max
        ({
            tree[2*node+1][2],
            tree[2*node+2][2],
            tree[2*node+1][0] + tree[2*node+2][1]
        });


        tree[node][3] = tree[2*node+1][3] + tree[2*node+2][3];
    }

    void update(int l,int r,int val)
    {
        updateaux(0,size-1,0,l,r,val);
    }

    long long query()
    {
        return max({tree[0][0],tree[0][1],tree[0][2],tree[0][3]});
    }
};

int main()
{
    int n,m;
    cin >> n >> m;
    seg tree(n);

    int l,v,r;

    while (m--)
    {
        cin >> l >> r >> v;
        tree.update(l,--r,v);
        cout << tree.query() << endl;
    }
}