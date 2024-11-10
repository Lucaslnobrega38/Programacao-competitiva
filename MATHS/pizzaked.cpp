#include <bits/stdc++.h>
using namespace std;

int main()
{
    int res = 0;
    int soma = 0;
    int begin = 0;

    int n;
    cin >> n;

    int arr[2*n];

    for (int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    for (int i=n;i<2*n;i++)
    {
        arr[i] = arr[i-n];
    }

    for (int i=0;i<2*n;i++)
    {   
        soma += arr[i];

        if (soma < 0)
        {
            soma = 0;
            begin = i+1;
            continue;
        }

        if ((i-begin+1) > n)
        {
            soma = max(soma-arr[begin],arr[i]);
            if (arr[i] > soma - arr[begin])
            {
                soma = arr[i];
                begin = i;
            }
            else
            {
                soma = soma - arr[begin];
                begin++;
            }
        }

        res = max(res,soma);
    }

    cout << res;
}