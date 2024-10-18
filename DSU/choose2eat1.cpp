#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n,m;
vector<int> id;

vector<int> pai;
vector<int> peso;

long long expo(long long a,int b)
{
    long long res = 1;

    while (b)
    {
        if (b&1) res *= a;

        a*=a;

        a = a%m;
        res = res%m;

        b = b >> 1;
    }

    return res;
}

long long calc(int a,int b)
{   
    long long res;

    res = (expo(a,b)+expo(b,a))%m;


    return res;
}

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

    if (peso[ga] > peso[gb]){pai[gb]=ga;return true;}
    if (peso[gb] > peso[ga]){pai[ga]=gb;return true;}

    pai[gb] = ga;
    peso[ga]++;

    return true;

}

int main()
{
    cin >> n >> m;

    long long res = 0;

    id.resize(n+1);
    pai.resize(n+1);
    peso.resize(n+1);

    for (int i=1;i<=n;i++)
    {
        cin >> id[i];
        pai[i] = i;
        peso[i] = 0;
    }

    vector<pair<long long,pair<int,int>>> arestas;

    for (int i=1;i<=n;i++)
    for (int j=i+1;j<=n;j++)
        arestas.push_back({calc(id[i],id[j]),{i,j}});

    sort(arestas.begin(),arestas.end(),greater<pair<long long,pair<int,int>>>());

    int cont = 0;

    for (int i=0;i<arestas.size() && cont <= n-1;i++)
    {
        if (join(arestas[i].second.first,arestas[i].second.second))
        {
            res += arestas[i].first;
            cont++;
        }
    }

    cout << res;
}