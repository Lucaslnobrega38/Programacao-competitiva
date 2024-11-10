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
        lazy.resize(sizet,0);
    }

    void unlazy(int tl,int tr,int node)
    {
        if (lazy[node] == 0) return;

        tree[node] += lazy[node];

        if (tl != tr)
        {
            lazy[2*node+1] += lazy[node];
            lazy[2*node+2] += lazy[node];
        }

        lazy[node] = 0;
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

        int mid = (tl+tr)>>1;

        updateaux(tl,mid,2*node+1,l,r);
        updateaux(mid+1,tr,2*node+2,l,r);

        tree[node] = max(tree[2*node+1],tree[2*node+2]);
    }

    void update(int l,int r)
    {
        updateaux(0,size-1,0,l,r);
    }

    int queryaux(int tl,int tr,int node,int l,int r)
    {
        unlazy(tl,tr,node);

        if (tl > r or tr < l) return 0;

        if (tl >= l and tr <= r) return tree[node];

        int mid = (tl+tr) >> 1;

        return max(queryaux(tl,mid,2*node+1,l,r),queryaux(mid+1,tr,2*node+2,l,r));
    }

    int query(int l,int r)
    {
        return queryaux(0,size-1,0,l,r);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<int,int> dict;

    vector<pair<int,int>> pares(n);
    vector<int> nums(n+n);

    for (int i=0;i<n;i++)
    {
        cin >> pares[i].first;
        cin >> pares[i].second;

        nums[2*i] = pares[i].first;
        nums[2*i + 1] = pares[i].second;
    }

    int q;
    cin >> q;

    vector<pair<int,int>> querys(q);

    for (int i=0;i<q;i++)
    {
        cin >> querys[i].first;
        cin >> querys[i].second;

        nums.push_back(querys[i].first);
        nums.push_back(querys[i].second);
    }

    sort(nums.begin(),nums.end());
    int id = 1;
    for (int i=0;i<nums.size();i++)
    {
        if (dict[nums[i]] == 0)
        {
            dict[nums[i]] = id;
            id++;
        }
    }

    seg tree(id+1);

    for (int i=0;i<n;i++)
    {
        tree.update(dict[pares[i].first],dict[pares[i].second]);
    }

    for (int i=0;i<q;i++)
    {
        cout << tree.query(dict[querys[i].first],dict[querys[i].second]) << endl;
    }
}