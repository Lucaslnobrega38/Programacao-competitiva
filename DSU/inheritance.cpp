#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int n,m,k;
class dsu
{
public:

    vector<int> pai;
    vector<int> peso;

    dsu()
    {   
        pai.resize(n+1);
        peso.resize(n+1,0);

        for (int i=0;i<=n;i++) pai[i] = i;
    }

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

        if (peso[ga] > peso[gb]){pai[gb] = ga; return;}
        if (peso[gb] > peso[ga]){pai[ga] = gb; return;}

        pai[gb] = ga;
        peso[ga]++;
    }

    bool same(int a,int b)
    {
        return (find(a) == find(b));
    }
};

int main()
{
    
    cin >> n >> m >> k;

    int a,b,d;

    vector<array<int,4>> arestas;    // dabi

    for (int i=0;i<m;i++)
    {
        cin >> a >> b >> d;
        arestas.push_back({d,a,b,i});
    }

    sort(arestas.begin(),arestas.end(),greater<array<int,4>>());

    vector<int> res(m);

    vector<dsu> children(k+1);

    int ini,end,found,mid;
    for (int i=0;i<m;i++)
    {
        //buscar o filho

        //arestas[i][1] = a
        //arestas[i][2] = b
        // sendo o indice 0 o nada

        ini = 1;
        end = k;
        found = 0;

        while (ini <= end)
        {
            mid = ((ini+end)/2);

            if (children[mid].same(arestas[i][1],arestas[i][2]))
            {
                ini = mid+1;
            }
            else
            {
                found = mid;
                end = mid-1;
            }

        }

        if (found)
        children[found].join(arestas[i][1],arestas[i][2]);

        res[arestas[i][3]] = found;
        
    }

    for (auto x : res) cout << x << endl;
}