#include <bits/stdc++.h>
using namespace std;


long long solve(long long arg)
{
    long long divs = 1;
    for (int i=2;i<=sqrt(arg);i++)
    {
        if (arg%i==0)
        {
            int expo = 0;

            while(arg%i == 0)
            {
                arg /= i;
                expo++;
            }

            divs = divs*(expo+1);
        }
    }


    if (arg > 1){divs*=2;}

    return divs;
}

int main()
{
    int n;
    cin >> n;
    long long arr[n];

    for (int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    for (int i=0;i<n;i++)
    {
        cout << solve(arr[i]) << endl;
    }
}