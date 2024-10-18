#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

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

    void update(int index,int val)
    {
        while (index < size)
        {
            arr[index] += val;
            index += (index & -index);
        }
    }

    long long sum(int r)
    {
        long long ans = 0;

        while (r > 0)
        {
            ans += arr[r];
            r -= (r & -r);
        }

        return ans;
    }

    long long sum(int l,int r)
    {
        return sum(r) - sum(l-1);
    }
};

int main()
{
    int t;
    cin >> t;

    int temp;
    int n;
    long long res;
    while (t--)
    {
        res = 0;
        cin >> n;
        fenwick tree(n);

        vector<pair<int,int>> arr;
        arr.push_back({0,0});

        for (int i=1;i<=n;i++)
        {
            cin >> temp;
            arr.push_back({temp,i});
        }

        sort(arr.begin(),arr.end());

        for (int i=1;i<=n;i++)
        {
            tree.update(arr[i].second,1);
            res += tree.sum(arr[i].second+1,n);
        }

        cout << res << endl;
    }
}