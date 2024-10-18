#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i=0;i<n;i++) cin >> arr[i];

    vector<int> pilhas;

    pilhas.push_back(arr[0]);

    int ini, end, mid;

    for (int i=1;i<n;i++)
    {
        auto it = lower_bound(pilhas.begin(),pilhas.end(),arr[i]);
        
        if (it == pilhas.end())
        {
            pilhas.push_back(arr[i]);
        }
        else
        {
            *it = arr[i];
        }

    }

    cout << pilhas.size();
}