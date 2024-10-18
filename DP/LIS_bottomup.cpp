#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> aux(n,1);

    aux[0] = 1;

    for (int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    for (int i=1;i<n;i++)
    {
        for (int j=0;j<i;j++)
        {
            if (arr[i] > arr[j]) aux[i] = max(aux[i],aux[j]+1);
        }
    }

    for (auto x : aux)
    {
        cout << x << " ";
    }

    
}