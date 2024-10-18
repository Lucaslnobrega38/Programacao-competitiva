#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

class fenwick
{
public:
    long long size = 1000011;
    vector<int> arr;

    fenwick()
    {
        arr.resize(size,0);
    }

    void set(int index)
    {
        while (index < size)
        {
            arr[index] += 1;
            index += (index & -index);
        }
    }

    void del(int index)
    {
        while (index < size)
        {
            arr[index] -= 1;
            index += (index & -index);
        }
    }

    int sum(int r)
    {
        int ans = 0;

        while (r > 0)
        {
            ans += (int)arr[r];
            r -= (r & -r);
        }

        return ans;
    }

    int sum(int l,int r)
    {
        return sum(r) - sum(l);
    }
};

int main()
{
    int t;
    cin >> t;

    int m,r;

    int watch;
    int max_index;
    while (t--)
    {
        // movies, request
        cin >> m >> r;

        fenwick tree;
        vector<int> indexes(m+1);
        max_index = m;
        for (int i=1;i<=m;i++)
        {
            indexes[i] = m-i+1;
            tree.set(i);
        }

        while (r--)
        {
            cin >> watch;

            cout << tree.sum(indexes[watch],tree.size-1) << endl;
            //swap(indexes[watch],indexes[max_index_el]);

            tree.del(indexes[watch]);
            tree.set(++max_index);
            indexes[watch] = max_index;
            

        }
    }
}