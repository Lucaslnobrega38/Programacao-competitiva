#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ii pair<int,int>

class node
{
public:
    vector<ii> prefs;
    vector<ii> sufs;
    int count;
    int gcd;

    node()
    {
        vector<ii> prefs;
        vector<ii> sufs;
        count = 0;
        gcd = INT_MAX;
    }
    

} ; 

class seg
{
public:
    int size;
    int sizet;
    vector<node> tree;

    seg(int arg)
    {
        size = arg;
        sizet = 4*arg;
        tree.resize(sizet);
    }

    node merge(node a, node b)
    {
        node res;
        res.gcd = __gcd(a.gcd,b.gcd);
        res.count = a.count + b.count;

        int t = 0;
        int pb = b.prefs.size()-1; // vai no prefixo de b

        for (auto par : b.prefs) t += par.second;

        for (auto apar : a.sufs)
        {
            for (;pb>=0 && __gcd(b.prefs[pb].first,apar.first) == 1;pb--)
            {
                t -= b.prefs[pb].second;
            }

            res.count += 1ll*t*apar.second;
        }

        


        res.prefs = a.prefs;

        int temp;
        int tgcd;
        if (a.gcd > 1)
        {
            tgcd = a.gcd;
            for (auto par : b.prefs)
            {
                temp = __gcd(par.first,tgcd);

                if (temp == 1) break;

                if (temp != res.prefs[res.prefs.size()-1].first)
                {
                    res.prefs.push_back({temp,par.second});
                }
                else
                {
                    res.prefs[res.prefs.size()-1].second += par.second;
                }

                tgcd = temp;

            }
        }

        res.sufs = b.sufs;

        if (b.gcd > 1)
        {
            tgcd = b.gcd;
            for (auto par : a.sufs)
            {
                temp = __gcd(tgcd,par.first);

                if (temp == 1) break;

                if (temp != res.sufs[res.sufs.size()-1].first)
                {
                    res.sufs.push_back({temp,par.second});
                }
                else
                {
                    res.sufs[res.sufs.size()-1].second += par.second;
                }

                tgcd = temp;

            }

        }

        return res;
    }

    void buildaux(int tl,int tr,int node,vector<int> &arr)
    {
        if (tl == tr) 
        {
            tree[node].gcd = arr[tl];
            tree[node].prefs.push_back({arr[tl],1});
            tree[node].sufs.push_back({arr[tl],1});
            tree[node].count = (arr[tl] > 1); 
            return;
        }

        int mid = (tl+tr) >> 1;

        buildaux(tl,mid,2*node+1,arr);
        buildaux(mid+1,tr,2*node+2,arr);

        tree[node] = merge(tree[2*node+1],tree[2*node+2]);
    }

    void build(vector<int> &arr)
    {
        buildaux(0,size-1,0,arr);
    }

    void updateaux(int tl,int tr,int node,int index,int val)
    {
        if (tl == tr)
        {
            tree[node].gcd = val;
            tree[node].prefs = {{val,1}};
            tree[node].sufs = {{val,1}};
            tree[node].count = (val > 1);
            return;
        }

        int mid = (tl + tr) >> 1;

        if (index <= mid)
        {
            updateaux(tl,mid,2*node+1,index,val);
        }
        else
        {
            updateaux(mid+1,tr,2*node+2,index,val);
        }

        tree[node] = merge(tree[2*node+1],tree[2*node+2]);
    }

    void update(int index,int val)
    {
        updateaux(0,size-1,0,index,val);
    }

    node queryaux(int tl,int tr,int Node,int l,int r)
    {
        if (tl > r or tr < l)
        {
            node res;
            res.gcd = 1;
            res.count = 0;
            res.prefs = {{1,0}};
            res.sufs = {{1,0}};
            return res;
        }

        if (tl >= l and tr <= r)
        {
            return tree[Node];
        }

        int mid = (tl+tr) >> 1;

        return merge(queryaux(tl,mid,2*Node+1,l,r) , queryaux(mid+1,tr,2*Node+2,l,r));
    }

    node query(int l,int r)
    {
        return queryaux(0,size-1,0,l,r);
    }
};

int main()
{
    int n,m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i=0;i<n;i++) cin >> arr[i];

    seg tree(n);
    tree.build(arr);

    int a,b,c;

    while (m--)
    {
        cin >> a >> b >> c;

        if (a == 1)
        {
            tree.update(--b,c);
        }
        else
        {
            cout << tree.query(--b,--c).count << endl;
        }
    }
}