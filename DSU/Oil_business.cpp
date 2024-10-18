#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

vector<int> pai;
vector<int> peso;

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

    if (peso[ga] > peso[gb]){ pai[gb] = ga; return true;}
    if (peso[gb] > peso[ga]){ pai[ga] = gb; return true;}

    pai[gb] = ga;
    peso[ga]++;
    return true;
}

int main()
{
    long long s;
    int n,m;
    cin >> n >> m >> s;

    vector<array<int,5>> arestas; // dabi_at 

    pai.resize(n+1);
    peso.resize(n+1);

    for (int i=1;i<=n;i++)
    {
        pai[i] = i;
        peso[i] = 0;
    }

    int a,b,d;
    for (int i=1;i<=m;i++)
    {
        cin >> a >> b >> d;
        arestas.push_back({d,a,b,i,0});
    }

    sort(arestas.begin(),arestas.end());

    // encontrado arvore geradora maxima

    for (int i=m-1;i>=0;i--)
    {
        if (join(arestas[i][1],arestas[i][2])) arestas[i][4] = 1;
    }

    vector<int> res;

    for (int i=0;i<m;i++)
    {
        if (arestas[i][4] == 0 && s >= arestas[i][0])
        {
            s -= arestas[i][0];
            res.push_back(arestas[i][3]);
        }
    }

    cout << res.size() << endl;

    for (auto x : res) cout << x << " ";
}