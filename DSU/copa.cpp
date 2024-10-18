#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

vector<int> pai;
vector<int> peso;
long long res = 0;
long long tres = 0;

int find(int x)
{
    if (pai[x] == x) return x;

    return pai[x] = find(pai[x]);
}

void join(int a,int b,int dist)
{
    int ga = find(a);
    int gb = find(b);

    if (ga == gb) return;

    tres += dist;

    if (peso[ga] > peso[gb]) {pai[gb] = ga; return;}

    if (peso[gb] > peso[ga]) {pai[ga] = gb; return;}

    pai[gb] = ga;
    peso[ga]++;

}

int main()
{
    int n,f,r;
    cin >> n >> f >> r;

    pai.resize(n+1);
    peso.resize(n+1);

    for (int i=0;i<=n;i++)
    {
        pai[i] = i;
        peso[i] = 0;
    }

    vector<array<int,3>> arestas;

    int a,b,d;
    for (int i=0;i<f;i++)
    {
        cin >> a >> b >> d;
        arestas.push_back({d,a,b});
    }

    sort(arestas.begin(),arestas.end());

    for (int i=0;i<f;i++)
    {
        join(arestas[i][1],arestas[i][2],arestas[i][0]);
    }
    
    res += tres;
    tres = 0;
    
   

    arestas.clear();

    for (int i=0;i<r;i++)
    {
        cin >> a >> b >> d;
        arestas.push_back({d,a,b});
    }

    sort(arestas.begin(),arestas.end());

    for (int i=0;i<r;i++)
    {   
        join(arestas[i][1],arestas[i][2],arestas[i][0]);
    }   

    cout << res + tres;

}