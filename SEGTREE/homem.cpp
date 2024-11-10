#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define t array<int,3>

// 1 = homem
// 2 = elefante
// 3 = rato

t soma(t a, t b)
{
    t res = {0,0,0};

    res[0] = a[0] + b[0];
    res[1] = a[1] + b[1];
    res[2] = a[2] + b[2];

    return res;
}

class seg
{
public:
    int size;
    int sizet;
    vector<t> tree;
    vector<int> lazy;

    seg(int arg)
    {
        size = arg;
        sizet = arg*4;
        tree.resize(sizet,{0,0,0});
        lazy.resize(sizet,0);
    }

    void unlazy(int tl,int tr,int node)
    {
        lazy[node] = lazy[node] % 3;

        if (lazy[node] == 0) return;

        t res = {0,0,0};

        if (lazy[node] == 1) // 1 passo
        {
            res[0] = tree[node][2];
            res[1] = tree[node][0];
            res[2] = tree[node][1];

            tree[node] = res;
        }
        else // 2 passos
        {
            res[0] = tree[node][1];
            res[1] = tree[node][2];
            res[2] = tree[node][0];

            tree[node] = res;
        }

        if (tl != tr)
        {
            lazy[2*node+1] += lazy[node];
            lazy[2*node+2] += lazy[node]; 
        }

        lazy[node] = 0;
    }

    void buildaux(int tl,int tr,int node)
    {
        if (tl == tr)
        {
            tree[node] = {1,0,0};
            return;
        }

        int mid = (tl + tr) >> 1;

        buildaux(tl,mid,2*node+1);
        buildaux(mid+1,tr,2*node+2);

        tree[node] = soma(tree[2*node+1],tree[2*node+2]);
    }

    void build()
    {
        buildaux(0,size-1,0);
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

        tree[node] = soma(tree[2*node+1],tree[2*node+2]);

    }

    void update(int l,int r)
    {
        updateaux(0,size-1,0,l,r);
    }

    t queryaux(int tl,int tr,int node,int l,int r)
    {
        unlazy(tl,tr,node);

        if (tl > r or tr < l) return {0,0,0};

        if (tl >= l and tr <= r)
        {
            return tree[node];
        }

        int mid = (tl+tr) >> 1;

        return soma(queryaux(tl,mid,2*node+1,l,r),queryaux(mid+1,tr,2*node+2,l,r));
    }

    t query(int l,int r)
    {
        return queryaux(0,size-1,0,l,r);
    }
};

int main()
{
    //mat[1][1] = 2;
    //mat[1][2] = 3;

    //mat[2][1] = 3;
    //mat[2][2] = 1;

    //mat[3][1] = 1;
    //mat[3][2] = 2;

    int n,m;
    char op;
    int a,b;

    t res;
    while (cin >> n >> m)
    {
        seg tree(n);
        tree.build();

        while (m--)
        {
            cin >> op >> a >> b;

            if (op == 'M')
            {
                tree.update(--a,--b);
            }
            else
            {
                res = tree.query(--a,--b);

                cout << res[0] << " " << res[1] << " " << res[2] << endl;
            }

        }

        cout << endl;
    }
}