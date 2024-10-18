#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<int,int>> arr(n);

    for (int i=0;i<n;i++)
    {
        cin >> arr[i].first;  // deadline
        cin >> arr[i].second; //reward
    }

    sort(arr.begin(),arr.end());

    long long time = 0;
    long long reward = 0;

    for (int i=0;i<n;i++)
    {
        time += (long long)arr[i].first;
        reward += (long long)arr[i].second - time;
    }

    cout << reward;
}