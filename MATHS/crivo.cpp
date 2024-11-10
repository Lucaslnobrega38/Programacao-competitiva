#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n;
vector<int> spf;

void crivo()
{
    vector<int> primo;
    primo.resize(n+1,-1);

    for (int i=2;i<=n;i++)
    {
        if (primo[i] == -1)
        {
            primo[i] = 1;
            cout << i << " ";

            for (int j = i+i ;j<=n; j+=i)
            {
                primo[j] = 0;
            }


        }
    }
}


void spff()
{
    spf.resize(n+1,0);

    for (int i=2;i<=n;i++)
    {
        if (spf[i] == 0)
        {
            spf[i] = i;

            for (int j=i+i;j<=n;j+=i)
            {
                if (spf[j] == 0)
                    spf[j] = i;
            }
        }
    } 

    for (int i : spf) cout << i << " ";
    cout << endl << endl;
}

// -1 = indefinido
//  0 = composto
//  1 = primo

int main()
{
    n = 100;

    //crivo();
    spff();

    // usando spf para fatorar um numero qualquer

    int v;
    std::cin >> v;
    vector<int> fatores;

    while (v > 1)
    {  
        fatores.push_back(spf[v]);
        
        v /= spf[v];
    }

    for (int i: fatores) cout << i << " ";
}