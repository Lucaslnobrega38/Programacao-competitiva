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

    if (peso[ga] > peso[gb]){pai[gb] = ga;return true;}
    if (peso[gb] > peso[ga]){pai[ga] = gb;return true;}

    pai[gb] = ga;
    peso[ga]++;

    return true;
}

int main()
{
    int n,m,q;
    cin >> n >> m >> q;


    pai.resize(n+1);
    peso.resize(n+1);

    for (int i=0;i<=n;i++)
    {
        pai[i] = i;
        peso[i] = 0;
    }

    vector<array<int,5>> arestas; // dab_qi

    int a,b,d;
    for (int i=0;i<m;i++)
    {
        cin >> a >> b >> d;

        arestas.push_back({d,a,b,0,-1});
    }

    vector<bool> res(q);

    for (int i=0;i<q;i++)
    {
        cin >> a >> b >> d;

        arestas.push_back({d,a,b,1,i});
    }

    sort(arestas.begin(),arestas.end());

    for (int i=0;i<q+m;i++)
    {
        if (arestas[i][3] == 0)
        {
            join(arestas[i][1],arestas[i][2]);
        }
        else
        {
            if (find(arestas[i][1]) != find(arestas[i][2]))
            {
                res[arestas[i][4]] = true;
            }
            else
            {
                res[arestas[i][4]] = false;
            }
        }
    }

    for (bool x : res)
    {
        if (x){cout << "Yes";}
        else{cout << "No";}

        cout << endl;
    }
 
}