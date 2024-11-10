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

    void buildaux(int tl,int tr,int node, vector<int> &v)
    {
        if (tl == tr)
        {
            if (v[tl] == 0)
            {
                tree[node] = 0;
                return;
            }

            if (v[tl] > 0)
            {
                tree[node] = 1;
                return;
            }

            tree[node] = -1;
            return;
        }

        int mid = (tl+tr) >> 1;

        buildaux(tl,mid,2*node+1,v);
        buildaux(mid+1,tr,2*node+2,v);

        tree[node] = tree[2*node+1]*tree[2*node+2];
    }

    void build(vector<int> &v)
    {
        buildaux(0,size-1,0, v);
    }

    void updateaux(int tl,int tr,int node,int index,int val)
    {
        if (tl == tr)
        {
            if (val == 0){tree[node] = 0; return;}
            if (val > 0){tree[node] = 1; return;}

            tree[node] = -1;

            return;
        }

        int mid = (tl+tr) >> 1;

        if (index <= mid)
        {
            updateaux(tl,mid,2*node+1,index,val);
        }
        else
        {
            updateaux(mid+1,tr,2*node+2,index,val);
        }

        tree[node] = tree[2*node+1]*tree[2*node+2];
    }

    void update(int index,int val)
    {
        updateaux(0,size-1,0,index,val);
    }

    int queryaux(int tl,int tr,int node,int l,int r)
    {
        if (tl > r or tr < l) return 1;

        if (tl >= l and tr <= r) return tree[node];

        int mid = (tl+tr) >> 1;

        return queryaux(tl,mid,2*node+1,l,r)*queryaux(mid+1,tr,2*node+2,l,r);
    }

    int query(int l,int r)
    {
        return queryaux(0,size-1,0,l,r);
    }
};

int main()
{
    int op,a,b;
    vector<int> arr = {1,5,-2,4,3};
    seg tree(arr.size());
    tree.build(arr);
    while (1)
    {
        cin >> op >> a >> b;

        if (op == 1)
        {
            tree.update(--a,b);
        }
        else
        {
            cout << tree.query(--a,--b) << endl;
        }
    }
}