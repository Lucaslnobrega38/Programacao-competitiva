#include <bits/stdc++.h>
using namespace std;
#define endl "\n"


class fenwick
{
public:
    int size;
    vector<long long> arr;

    fenwick(int arg)
    {
        size = arg+1;
        arr.resize(size,0);
    }

    void update(int index,long long val)
    {
        while (index < size)
        {
            arr[index] += val;
            index += (index&-index);
        }
    }

    long long sum(int r)
    {
        long long res = 0;

        while (r > 0)
        {
            res += arr[r];
            r -= (r&-r);
        }

        return res;
    }

    long long sum(int r,int l)
    {
        return sum(r)-sum(l-1);
    }

};

int main()
{
    int n,q;
    cin >> n >> q;

    fenwick tree(n);
    vector<long long> arr(n+1,0);

    int temp;
    for (int i=1;i<=n;i++)
    {   
        cin >> temp;
        tree.update(i,temp);
        arr[i] = temp;
    }

    long long a,b;
    for (int i=0;i<q;i++)
    {
        cin >> temp >> a >> b;

        if (temp == 2)
        {
            cout << tree.sum(b,a) << endl;
        }
        else
        {
            tree.update(a,b-arr[a]);
            arr[a] = b;
        }
    }
}