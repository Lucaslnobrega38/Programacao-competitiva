#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
// contar inversões, mas ao contrário

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
        while (index < size)
        {
            arr[index] += val;
            index += (index & -index);
        }
    }

    int sum(int r)
    {
        int val = 0;

        while (r)
        {
            val += arr[r];
            r -= (r & -r);
        }

        return val;
    }
};

long long distq(long long a,long long b)
{
    return ((long long)a*a)+((long long)b*b);
}

int main()
{
    int n;
    cin >> n;

    long long a,b;
    vector<pair<long long,int>> arr;
    fenwick tree(n);

    for (int i=0;i<n;i++)
    {
        cin >> a >> b;
        arr.push_back({distq(a,b),i+1});
    }

    sort(arr.begin(),arr.end());

    long long ans = 0;

    for (int i=0;i<n;i++)
    {
        tree.add(arr[i].second,1);
        ans += tree.sum(arr[i].second-1);
    }

    cout << ans;
}