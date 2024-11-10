#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n;
long long w;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cin >> n >> w;
        vector<int> res;

        int el;

        long long sum = 0;
        int p = 0;

        for (int i=1;i<=n;i++)
        {
            cin >> el;
            if (el <= w)
            {
                if (el >= (w+1)/2){p = i;}
                else if (sum < (w+1)/2){sum += (long long)el;res.push_back(i);}
            }
        }

        if (p != 0){cout << 1 << endl << p << endl;}
        else if (sum >= (w+1)/2){cout << res.size() << endl;
        
        for (auto x : res) cout << x << " ";
        cout << endl;
        }
        else{cout << -1 << endl;}
    }
}