#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

// segment tree

// tamanho = 4n ou menos
// filhos de i = 2i e 2i+1 se 1 indexed
// filhos de i = 2i+1 e 2i+2 se 0 indexed
 

class segment
{
public:

    int size;
    vector<int> arr;
    int n;

    segment(int arg)
    {
        size = (arg*4); // 0 indexed
        n = arg;
        arr.resize(size,0);
    }

    void buildaux(int start,int end,int node,vector<int> &v)
    {
        if (start == end) 
        {
            arr[node] = v[start]; 
            return;
        }

        int mid = (start+end) >> 1;

        buildaux(start,mid,2*node+1,v);

        buildaux(mid+1,end,2*node+2,v);

        arr[node] = arr[2*node+1] + arr[2*node+2];
    }

    void build(vector<int> &v)
    {
        buildaux(0,v.size()-1,0,v);
    }

    int queryaux(int start,int end,int l,int r,int node)
    {
        if (start > r or end < l) return 0;
        // não há interseção

        if (start >= l and end <= r) return arr[node];
        // interseção completa

        int mid = (start+end) >> 1;
        // quando a interseção é parcial, usar recursão para 
        // encontrar nós filhos de interseção completa

        int res = 0;

        res += queryaux(start,mid,l,r,2*node + 1); // left
        res += queryaux(mid+1,end,l,r,2*node+2); // right

        return res;
    }

    int query(int l, int r)
    {
        return queryaux(0,n-1,l,r,0);

        // l e r são o range da query.
        // start e end são o range do respectivo nó
    }

    void updateaux(int start,int end,int node, int index,int val)
    {
        if (start == end) {arr[node] = val; return;}

        int mid = (start+end) >> 1;

        if (index <= mid)
        {
            updateaux(start,mid,2*node+1,index,val);
        }
        else
        {
            updateaux(mid+1,end,2*node+2,index,val);
        }

        arr[node] = arr[2*node+1] + arr[2*node+2];
    }

    void update(int index,int val)
    {
        updateaux(0,n-1,0,index,val);
    }   
    
};

int main()
{
    int n = 8;
    vector<int> arr = {2,3,5,6,8,1,2,1};

    segment tree(n);

    tree.build(arr);
}