#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {3,1,1,1,5,1,2,1};
    int tgt = 3;

    int n = arr.size();

    for (int i=1;i<n;i++)
    {
        arr[i] += arr[i-1];
    }

    int res = INT_MAX;

    for (int fi = 0;fi<n;fi++)
    for (int fe = fi;fi<n;fi++)
    for (int li=fe+1;li<n;li++)
    for (int le=li;le<n;le++)
    {
        int fsum,lsum;

        lsum = arr[le] - arr[li-1];

        if (fi > 0 )
        {
            fsum = arr[fe] - arr[fi-1];   
        }
        else
        {
            fsum = arr[fe];
        }

        if (fsum == lsum)
        {
            res = min((fe-fi+1)+(le-li+1),res);
        }
    }

    cout << res;

}