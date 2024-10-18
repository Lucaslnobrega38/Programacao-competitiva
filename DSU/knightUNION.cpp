#include <bits/stdc++.h>
using namespace std;

vector<int> pai;

int find(int x)
{
    if (pai[x] == x) return x;

    return pai[x] = find(pai[x]);
}

int main()
{
    int n,m;
    cin >> n >> m;

    vector<int> res(n+2,0);
    pai.resize(n+2);

    for (int i=0;i<=n+1;i++) pai[i] = i;

    int a,b,w;
    while (m--)
    {
        cin >> a >> b >> w;

        for (int i=find(a);i<=b;i=find(i+1))
        {
            if (i == w) continue;

            res[i] = w;
            pai[i] = i+1;
        } 
    }

    for (int i=1;i<=n;i++) cout << res[i] << " ";
}