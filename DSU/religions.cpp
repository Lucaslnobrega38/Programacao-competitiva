#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int grupos;
vector<int> pai;
vector<int> peso;

int find(int x)
{
    if (pai[x] == x) return x;

    return pai[x] = find(pai[x]);
}

void join(int a,int b)
{
    int ga = find(a);
    int gb = find(b);

    if (ga == gb) return;

    grupos--;
    if (peso[ga] > peso[gb]) pai[gb] = ga;
    if (peso[gb] > peso[ga]) pai[ga] = gb;

    if (peso[ga] == peso[gb])
    {
        pai[gb] = ga;
        peso[ga]++;
    }
}

int main()
{
    int n,m;
    int a,b;

    int count = 1;

    while (cin >> n >> m)
    {
        if (!(n bitor m)) return 0;

        cout << "Case " << count << ": ";

        pai.resize(n+1);
        peso.resize(n+1);

        for (int i=0;i<=n;i++)
        {
            pai[i] = i;
            peso[i] = 0;
        }

        grupos = n;
        while (m--)
        {
            cin >> a >> b;
            join(a,b);
        }

        cout << grupos << endl;
        count++;
    }
}