#include<bits/stdc++.h>
using namespace std;

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
    
    void buildaux(int tl,int tr,int node,vector<int> &arr)
    {
        if (tr == tl)
        {
            tree[node] = arr[tl];
            return;
        }
        
        int mid = (tr+tl) >> 1;
        
        buildaux(tl,mid,2*node + 1,arr);
        buildaux(mid+1,tr,2*node + 2,arr);
        
        tree[node] = tree[2*node+1]^tree[2*node+2];
    }
    
    void build(vector<int> &arr)
    {
        buildaux(0,size-1,0,arr);
    }
    
    int queryaux(int tl,int tr,int node, int l,int r)
    {
        if (tl > r or tr < l) return 0;
        
        if (tl >= l && tr <= r) return tree[node];
        
        int mid = (tl + tr) >> 1;
        
        return queryaux(tl,mid,2*node+1,l,r)^queryaux(mid+1,tr,2*node+2,l,r);
        
    }
    
    int query(int l,int r)
    {
        return queryaux(0,size-1,0,l,r);
    }
};

vector<int>solve(int n, vector<int>a, vector<vector<int>> queries)
{
    vector<int> res;
    
    seg tree(n);
    
    tree.build(a);
    
    int q = queries.size();
    
    for (int i=0;i<q;i++)
    {
        res.push_back(tree.query(queries[i][0]-1, queries[i][1]-1));
    }
    
    return res;
    
    
}