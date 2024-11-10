#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class seg
{
public:
    int size;
    int sizet;
    vector<long long> tree;
    vector<pair<long long,long long>> lazyfrente;
    vector<pair<long long,long long>> lazytras;

    seg(int arg)
    {
        size = arg;
        sizet = 4*arg;
        tree.resize(sizet,0);
        lazyfrente.resize(sizet,{0,0});
        lazytras.resize(sizet,{0,0});
    }

    void frenteunlazy(int tl,int tr,int node)
    {
        if (lazyfrente[node].first == 0 and lazyfrente[node].second == 0) return;

        if (tl == tr)
        {
            tree[node] += lazyfrente[node].first - lazyfrente[node].second*tl;
            lazyfrente[node] = {0,0};
            return;
        }
        else
        {
            lazyfrente[2*node+1].first += lazyfrente[node].first;
            lazyfrente[2*node+2].first += lazyfrente[node].first;

            lazyfrente[2*node+1].second += lazyfrente[node].second;
            lazyfrente[2*node+2].second += lazyfrente[node].second;


            lazyfrente[node] = {0,0};
        }
    }

    void frenteupdateaux(int tl,int tr,int node,int l,int r,long long v)
    {
        frenteunlazy(tl,tr,node);

        if (tl > r or tr < l) return;

        if (tl >= l and tr <= r)
        {
            lazyfrente[node].first += v;
            lazyfrente[node].second++;
            frenteunlazy(tl,tr,node);
            return;
        }

        int mid = (tl+tr) >> 1;

      
        frenteupdateaux(tl,mid,2*node+1,l,r,v);
        frenteupdateaux(mid+1,tr,2*node+2,l,r,v);
        
    }

    void frenteupdate(int l,long long v)
    {
        frenteupdateaux(0,size-1,0,l,l+v-1,v+l);
    }

    void trasunlazy(int tl, int tr,int node)
    {
        if (lazytras[node].first == 0 and lazytras[node].second == 0) return;

        if (tl == tr)
        {
            tree[node] += lazytras[node].first+lazytras[node].second*tl;
            lazytras[node] = {0,0};
            return;
        }
        else
        {
            lazytras[2*node+1].first += lazytras[node].first;
            lazytras[2*node+2].first += lazytras[node].first;

            lazytras[2*node+1].second += lazytras[node].second;
            lazytras[2*node+2].second += lazytras[node].second;

            lazytras[node] = {0,0};
        }
    }

    void trasupdateaux(int tl,int tr,int node,int l,int r,long long v)
    {
        trasunlazy(tl,tr,node);

        if (tl > r or tr < l) return;

        if (tl >= l and tr <= r)
        {
            lazytras[node].first += v;
            lazytras[node].second++;
            trasunlazy(tl,tr,node);
            return;
        }

        int mid = (tl+tr) / 2;

        trasupdateaux(tl,mid,2*node+1,l,r,v);
        trasupdateaux(mid+1,tr,2*node+2,l,r,v);
        
    }

    void trasupdate(int r,int v)
    {
        trasupdateaux(0,size-1,0,r-v+1,r,v-r);
    }

    long long queryaux(int tl,int tr,int node,int index)
    {
        frenteunlazy(tl,tr,node);
        trasunlazy(tl,tr,node);

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

    long long query(int index)
    {
        return queryaux(0,size-1,0,index);
    }

};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;

    seg tree(n);

    int op,in,v;
    for (int i=0;i<m;i++)
    {
        cin >> op >> in;

        if (op == 1)
        {
            cin >> v;

            tree.frenteupdate(--in,v);
            continue;
        }

        if (op == 2)
        {
            cin >> v;

            tree.trasupdate(--in,v);
            continue;
        }


        cout << tree.query(--in) << endl;
    }
}