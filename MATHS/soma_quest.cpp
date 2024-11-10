#include <bits/stdc++.h>
using namespace std;

int fatorial(int arg)
{
    if (arg == 1){return 1;}

    if (arg==0){return 0;}
    
    return arg+fatorial(arg-1);
}


int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr;
    vector<int> arr_no0;

    for (int i=0;i<n;i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    vector<int> zeros_esq;

    int contagem = 0;
    for (int i=0;i<n;i++)
    {
        if (arr[i]==0)
        {
            contagem++;
        }
        else
        {
            arr_no0.push_back(arr[i]);
            zeros_esq.push_back(contagem);
            contagem = 0;

        }
    }

    zeros_esq.push_back(contagem);
    int res = 0;
    if (k==0)
    {
        for (int i=0;i<zeros_esq.size();i++)
        {
            res += (fatorial(zeros_esq[i]));
        }
        cout << res;

        return 0;
    }
    


    for (int i=1;i<arr_no0.size();i++)
    {
        arr_no0[i] += arr_no0[i-1];
    }

    int l,r;
    l = r = 0;

    

    while(l < arr_no0.size())
    {
        int soma;
        if (l == 0){soma = arr_no0[r];}
        else{soma = arr_no0[r]-arr_no0[l-1];}

        if (soma > k)
        {
            l++;
        }

        if (soma < k)
        {
            r++;
        }

        if (soma == k)
        {
            res += (zeros_esq[l]+1)*(zeros_esq[r+1]+1);
            r++;
            l++;
        }

        if (l>r)
        {
            r++;
        }
    }

    cout << res;
}