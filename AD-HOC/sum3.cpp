#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define trio tuple<ll,int,int>

int main()
{
    int n;
    ll x;

    cin >> n >> x;

    vector<pair<ll,int>> arr(n);
    for (int i=0;i<n;i++)
    {
        cin >> arr[i].first;
        arr[i].second = i+1;
    }

    sort(arr.begin(),arr.end());

    for (int i=0;i<n;i++)
    {
        int ini = 0;
        int end = n-1;

        ll tgt = x - arr[i].first;
        ll sum;

        while (ini<end)
        {
            sum = arr[ini].first + arr[end].first;
        
            if (sum == tgt)
            {
                if (arr[i].second != arr[ini].second && arr[i].second != arr[end].second)
                {
                    cout << arr[i].second << " " << arr[ini].second << " " << arr[end].second;
                    return 0;
                }
            
                if (arr[end].first - arr[end].first < arr[ini+1].first-arr[ini].first)
                {
                    end--;
                }
                else
                {
                    ini++;
                }

                continue;
            }


            if (sum > tgt)
            {
                end--;
            }
            else
            {
                ini++;
            }
        }

    }
    
    cout << "IMPOSSIBLE";
}