#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int contagem = 1;
    while (1)
    {
        if (n == 0){break;}
        cout << "Teste " << contagem << "\n";

        vector<int> arr(n+1);
        arr[0]=0;
        int fav,cont;

        for (int i=1;i<=n;i++)
        {
            cin >> fav >> cont;
            arr[i] = fav-cont;
        }

        for (int i=1;i<=n;i++)
        {
            arr[i] += arr[i-1];
        }

        int begin,end,res = INT_MIN;
        int sum;

        for (int j=n;j>=1;j--)
        {
            for (int i=1;i<=j;i++)
            {
                sum = arr[j]-arr[i-1];

                if (sum > res)
                {
                    res = sum;
                    begin = i;
                    end = j;
                    continue;
                }
                if (sum == res)
                {
                    if ((end - begin)<(j-i))
                    {
                        begin = i;
                        end = j;
                    }
                }
            }
        }

        if (res > 0)
        {
            cout << begin << " " << end << " \n";
        }
        else
        {
            cout << "nenhum\n";
        }

        cout << "\n";
        contagem++;
        cin >> n;
    }
}