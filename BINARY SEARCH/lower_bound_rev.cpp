#include <bits/stdc++.h>
using namespace std;

int bs(vector<int> arr,int val)
{
    int ini=0;
    int end = arr.size()-1;
    int res = -1;

    int mid;
    while (ini <= end)
    {
        mid = (ini+end)/2;

        if (arr[mid] == val)
        {
            res = mid;
            return res;
        }

        if (arr[mid] > val)
        {
            end = mid-1;
        }
        else
        {
            ini = mid+1;
        }
    }

    return -1;
}

int maior_igual(vector<int> arr,int val)
{
    int ini=0;
    int end = arr.size()-1;
    int res = -1;
    int mid;

    while (ini<=end)
    {
        mid = (ini+end)/2;

        if (arr[mid] >= val)
        {
            res = mid;
            end = mid-1;
        }
        else
        {
            ini = mid+1;
        }
    }

    return res;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i=0;i<n;i++) cin >> arr[i];

    int sr;
    cin >> sr;

    cout << bs(arr,sr);
    cout << endl;

    cout << maior_igual(arr,sr);
    cout << endl;

    for (int i=0;i<n;i++) cout << arr[i] << " ";
}