#include <bits/stdc++.h>
using namespace std;

class fenwick
{
public:
    int size;
    vector<int> arr;

    fenwick(int arg)
    {
        size = arg+1;
        arr.resize(size,0);
    }

    void add(int index,int val)
    {
        index++;

        while (index < size)
        {
            arr[index] += val;
            index += (index & (-index));
        }
    }

    int sum(int r)
    {
        int res = 0;
        while (r)
        {
            res += arr[r];
            r -= (r&(-r));
        }

        return res;
    }
};

int main()
{
    int n,q;
    cin >> n >> q;

    vector<int> arr(n);

    fenwick tree(n);

    for (int i=0;i<n;i++) cin >> arr[i];

    for (int i=0;i<n;i++)
    {
        tree.add(i,arr[i]);
    }

    int op;
    int a,b;

    while (q--)
    {
        cin >> op;

        if (op == 1)
        {
            cin >> a;
            cout << tree.sum(a) << "\n";
        }
        else
        {
            cin >> a >> b;

            tree.add(a-1,b-arr[a-1]);
            arr[a-1] = b;
        }
    }

}