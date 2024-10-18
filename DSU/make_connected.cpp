#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n,m;
vector<long long> ids;
vector<pair<long long,pair<int,int>>> arestas; // dab

vector<int> pai;

int find(int x)
{
    if (pai[x] == x) return x;

    return pai[x] = find(pai[x]);
}

bool join(int a,int b)
{
    int ga = find(a);
    int gb = find(b);

    if (ga == gb) return false;

    pai[gb] = ga;

    return true;
}


int main()
{
    long long res = 0;
    cin >> n >> m;

    if (m == 0)
    {
        pai.resize(n+1);
        ids.resize(n+1);
        for (int i=1;i<=n;i++) pai[i] = i;
        for (int i=1;i<=n;i++) cin >> ids[i];

        sort(ids.begin(),ids.end());

        res = accumulate(ids.begin(),ids.end(),0LL) + ids[1]*(n-2);

        cout << res;
        return 0;

    }

    pai.resize(n+1);
    ids.resize(n+1);

    for (int i=1;i<=n;i++) pai[i] = i;

    for (int i=1;i<=n;i++) cin >> ids[i];
    

    int a,b;
    long long d;

    for (int i=0;i<m;i++)
    {   
        cin >> a >> b >> d;

        arestas.push_back({d,{a,b}});
    }

    for (int i=1; i <=n;i++)
    for (int j=i+1;j<=n;j++)
    {
        arestas.push_back({ids[i]+ids[j],{i,j}});
    }

    sort(arestas.begin(),arestas.end());

    for (int i=0;i<arestas.size();i++)
    {
        if (join(arestas[i].second.second,arestas[i].second.first))
        {
            res += arestas[i].first;
        }
    }

    cout << res;
}