#include <bits/stdc++.h>
using namespace std;

// fenwick tree
// 1 based index

class fenwick
{
public:

    vector<int> arr;
    int size;

    fenwick(int arg)
    {
        size = arg+1;
        arr.resize(size,0);
    }

    void add(int de,int para)
    {
        de++; // 1 based index

        while (de < size)
        {
            arr[de] += para;
            de += (de & (-de));
        }
    }

    int sum(int r)
    {
        r++;
        int ans = 0;
        while (r)
        {
            ans += arr[r];
            r -= (r&(-r));
        }

        return ans;
    }

    int sum (int l,int r)
    {
        return sum(r+1)-sum(l);
    }

};

int main()
{
   
}