#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

vector<int> pai;
vector<int> peso;
long long res = 0;

int find(int x)
{
    if (pai[x] == x)return x;

    return pai[x] = find(pai[x]);
}

void join(int a,int b,long long val)
{
    int ga = find(a);
    int gb = find(b);

    if (ga == gb)
    {
        return;
    }

    res += val;

    if (peso[ga] > peso[gb])
    {
        pai[gb] = ga;
        return;     
    }

    if (peso[gb] > peso[ga])
    {
        pai[ga] = gb;
        return;
    }

    pai[gb] = ga;
    peso[ga]++;
}

int main()
{
    int n,m;
    cin >> n >> m;

    pai.resize(n+1);
    peso.resize(n+1);

    for (int i=0;i<=n;i++)
    {
        pai[i] = i;
        peso[i] = 0;
    }

    vector<array<int,3>> dab;

    int a,b,d;
    for (int i=0;i<m;i++)
    {
        cin >> a >> b >> d;
        dab.push_back({d,a,b});
    }

    sort(dab.begin(),dab.end());

    for (int i=0;i<m;i++)
    {
        
        join(dab[i][1],dab[i][2],dab[i][0]);
    }

    cout << res;
}