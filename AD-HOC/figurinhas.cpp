#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, c , m;
    cin >> n >> c >> m;

    vector< pair<int,bool>> figuras;


    for (int i=0;i<n;i++)
    {
        figuras.push_back({i,false});
    }

    for (int i=0;i<c;i++)
    {
        int temp;
        cin >> temp;

        figuras[temp-1].second = true;
        
    }

    for (int i=0;i<m;i++)
    {
        int temp;
        cin >> temp;
        
        figuras[temp-1].second = false;
    }

    int cont = 0;
    for (int i=0;i<n;i++)
    {
        if (figuras[i].second) cont++;
    }

    cout << cont;

    

}