#include <bits/stdc++.h>
using namespace std;

class seg
{
public:
    int sizet;
    int size;
    vector<int> tree;
    vector<int> lazy;

    seg(int arg)
    {
        size = arg;
        sizet = arg*4;
        tree.resize(sizet,0);
        lazy.resize(sizet,0);
        // lazy é uma árvore auxiliar
    }

    void buildaux(int tl,int tr,int node,vector<int> &arr)
    {
        if (tl == tr)
        {
            tree[node] = arr[tl];
            return;
        }

        int mid = (tl+tr) >> 1;

        buildaux(tl,mid,2*node+1,arr);
        buildaux(mid+1,tr,2*node+2,arr);

        tree[node] = tree[2*node+1] + tree[2*node+2];
    }

    void build(vector<int> &arr)
    {
        buildaux(0,size-1,0,arr);
    }

    void updateaux(int tl,int tr,int node,int l,int r,int val)
    {
        if (tl > r or tr < l) return;

        if (lazy[node] != 0)
        {
            tree[node] += lazy[node]*(tr-tl+1);

            if (tl != tr)
            {
                lazy[2*node+1] += lazy[node];
                lazy[2*node+2] += lazy[node]; 
            }

            lazy[node] = 0;
        }

        // ulanzy twice??

        if (tl >= l and tr <= r)
        {
            tree[node] += lazy[node]*(tr-tl+1);

            if (tl != tr)
            {
                lazy[2*node+1] += lazy[node];
                lazy[2*node+2] += lazy[node];
            }
            lazy[node] = 0;

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

    int queryaux(int tl,int tr,int node,int l,int r)
    {
        if (tl > r or tr < l) return 0;

        if (lazy[node] != 0)
        {
            // att pendente

            tree[node] += lazy[node] * (tr-tl+1);

            // a multiplicação se deve ao fato que essa é uma segtree
            // de soma, então o valor deve ser multiplicado pela quantidade 
            // de filhos.

            if (tl != tr)
            {
                lazy[2*node+1] += lazy[node];
                lazy[2*node+2] += lazy[node];
                // propagação
            }

            lazy[node] = 0;
        }

        if (tl >= l and tr <= r) return tree[node];

        int mid = (tl+tr) >> 1;

        return queryaux(tl,mid,2*node+1,l,r); + queryaux(mid+1,tr,2*node+2,l,r);
    }

    int query(int l,int r)
    {
        return queryaux(0,size-1,0,l,r);
    }

};

int main()
{

}