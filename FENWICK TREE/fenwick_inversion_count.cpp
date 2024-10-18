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

    int sum(int r)
    {
        int res = 0;

        while (r > 0)
        {
            res += arr[r];
            r -= (r & -r);
        }

        return res;
    }

    int sum(int r,int l)
    {
        return sum(r) - sum(l-1);
    }
};

int main()
{
    int n;

    while (cin >> n)
    {
        if (n == 0) return 0;

        vector<pair<int,int>> num_index;
        vector<int> res(n+1,0);
        fenwick tree(n);
        
        int temp;
        for (int i=0;i<n;i++)
        {
            cin >> temp;
            num_index.push_back({temp,i+1}); // 1 indexado
        }

        sort(num_index.begin(),num_index.end());

        int num,index;
        for (int i=0;i<n;i++)
        {
            num = num_index[i].first;
            index = num_index[i].second;

            tree.update(index,1);
            res[index] = tree.sum(n,index+1);
        }

        int a = 0;
        for (int i=0;i<=n;i++) a+=res[i];

        if (a&1){cout << "Marcelo" << endl;}
        else{cout << "Carlos" << endl;}
    }
}