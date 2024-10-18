#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int n;
vector<int> pai;
vector<int> peso;
vector< pair<int,int> > cords;
vector<int> direta;
vector<int> k;

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

    if (peso[ga] > peso[gb]){pai[gb] = ga;return true;}
    if (peso[gb] > peso[ga]){pai[ga] = gb;return true;}

    pai[gb] = ga;
    peso[ga]++;
    return true;
}

long long lenght(int a,int b)
{
    long long res = abs(cords[a].first-cords[b].first)
    + abs(cords[a].second - cords[b].second); 

    return res * (k[a] + k[b]);
}

int main()
{
    cin >> n;
    pai.resize(n+1);
    peso.resize(n+1);
    cords.resize(n+1,pair<int,int>());
    direta.resize(n+1);
    k.resize(n+1);

    vector<pair<long long,pair<int,int>>> arestas;
    // dab

    for (int i=0;i<=n;i++)
    {
        pai[i] = i;
        peso[i] = 0;
    }

    for (int i=1;i<=n;i++)
    {
        cin >> cords[i].first;
        cin >> cords[i].second;
    }

    for (int i=1;i<=n;i++)
    {
        cin >> direta[i];
    }

    for (int i=1;i<=n;i++)
    {
        cin >> k[i];
    }

    for (int i=1;i<=n;i++)
    {
        arestas.push_back({direta[i],{0,i}});
    }

    for (int i=1;i<=n;i++)
    for (int j=i+1;j<=n;j++)
    {
        arestas.push_back({lenght(i,j),{i,j}});
    }

    sort(arestas.begin(),arestas.end());
    long long soma = 0;

    vector<int> stations;
    vector<pair<int,int>> conns;

    for (int i=0;i<arestas.size();i++)
    {
        if (join(arestas[i].second.first,arestas[i].second.second))
        {
            soma += arestas[i].first;

            if (arestas[i].second.first == 0)
            {
                stations.push_back(arestas[i].second.second);
            }
            else
            {
                conns.push_back({arestas[i].second.first,arestas[i].second.second});
            }
        }
    }   

    cout << soma << endl;
    cout << stations.size() << endl;
    sort(stations.begin(),stations.end());

    for (int i : stations) cout << i << " ";

    cout << endl;

    cout << conns.size();

    cout << endl;

    for (auto p : conns)
    {
        cout << p.first << " " << p.second << endl;
    }
}