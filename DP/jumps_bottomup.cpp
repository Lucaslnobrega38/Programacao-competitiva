#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> aux(n,INT_MAX);

    aux[0] = 0;

    for (int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    for (int i=0;i<n;i++)
    {
        int num = arr[i];

        for (int j=1;j<=num;j++)
        {
            if (i+j >= n){break;}

            aux[i+j] = min(aux[i] + 1, aux[i+j]);

        }

    }

    for (auto x : aux)
    {
        cout << x << " ";
    }


}