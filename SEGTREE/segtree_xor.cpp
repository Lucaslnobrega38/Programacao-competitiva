#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

// OR -> XOR -> OR -> XOR -> OR ...

int l,m;

class segment
{
public:
    int size;
    int n;
    vector<int> arr;
    bool pxor;

    segment(int arg)
    {
        n = arg;
        size = arg*4;
        arr.resize(size,0);

        if ((l%2) == 0)
        {
            pxor = true;
            // ultima operação é xor
        }
        else
        {
            pxor = false;
            // ultima operação é or
        }
    }

    void buildaux(vector<int> &v, int begin, int end, int node,bool ppxor)
    {
        if (begin == end)
        {
            arr[node] = v[begin];
            return;
        }

        int mid = (begin+end) >> 1;

        buildaux(v,begin,mid,2*node+1,!ppxor);
        buildaux(v,mid+1,end,2*node+2,!ppxor);

        if (ppxor)
        {
            arr[node] = arr[2*node+1] ^ arr[2*node+2];
        }
        else
        {
            arr[node] = arr[2*node+1] bitor arr[2*node+2];
        }
    }

    void build(vector<int> &v)
    {
        buildaux(v,0,n-1,0,pxor);
    }

    int queryaux(int begin,int end,int l,int r,int node)
    {
        if (l > end or r < begin) return 0;

        if (begin >= l && end <= r) return arr[node];

        int mid = (begin+end) >> 1;

        return queryaux(begin,mid,l,r,2*node+1) + queryaux(mid+1,end,l,r,2*node+2);
    }

    int query(int l,int r)
    {
        return queryaux(0,n-1,l,r,0);
    }

    void updateaux(int begin,int end,int node,int index,int val,bool ppxor)
    {
        if (begin == end)
        {
            arr[node] = val;
            return;
        }

        int mid = (begin+end) >> 1;

        if (index <= mid)
        {
            updateaux(begin,mid,2*node+1,index,val,!ppxor);
        }
        else
        {
            updateaux(mid+1,end,2*node+2,index,val,!ppxor);
        }

        if (ppxor)
        {
            arr[node] = arr[2*node+1] ^ arr[2*node+2];
        }
        else
        {
            arr[node] = arr[2*node+1] bitor arr[2*node+2];
        }
    }

    void update(int index,int val)
    {
        updateaux(0,n-1,0,index,val,pxor);
    }
};

int main()
{
    cin >> l >> m;

    int size = (1<<l);

    vector<int> arr(size);
    for (int i=0;i<size;i++) cin >> arr[i];

    segment tree(size);
    tree.build(arr);
    //cout << tree.arr[0];

    int a,b;
    for (int i=0;i<m;i++)
    {
        cin >> a >> b;

        tree.update(a-1,b);

        cout << tree.arr[0];
        cout << endl;
    }

}