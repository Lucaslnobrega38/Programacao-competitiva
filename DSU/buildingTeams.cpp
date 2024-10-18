#include <bits/stdc++.h>
using namespace std;

int k1,k2;

class dsu
{
public:

    int size;
    vector<int> pai;

    dsu(int arg)
    {
        size = arg;
        pai.resize(size);

        for (int i=0;i<size;i++)
        {
            pai[i] = i;
        }
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

        if (ga == gb)
        {
            return false;
        }

        if (ga == k1 or ga == k2)
        {
            pai[gb] = ga;
            return true;
        }

        if (gb == k1 or gb == k2)
        {
            pai[ga] = gb;
            return true;
        }

        if (ga < gb)
        {
            pai[gb] = ga;
        }
        else
        {
            pai[ga] = gb;
        }

        return true;
    }
};

int main()
{
    int n,m;
    cin >> n >> m;

    dsu grupos((n+1)*2);
    int a,b;

    cin >> a >> b;

    grupos.join(a,n+b);
    grupos.join(b,n+a);

    k1 = a;
    k2 = b;

    for (int i=1;i<m;i++)
    {   
        cin >> a >> b;
        
        if (grupos.find(a) == grupos.find(b))
        {
            cout << "IMPOSSIBLE"; return 0;
        }
        else
        {
            grupos.join(a,n+b);
            grupos.join(b,n+a);
        }
    }
    int temp;
    for (int i=1;i<=n;i++)
    {
        temp = grupos.find(i);

        if (temp == k1)
        {
            cout << 1 << " ";
            continue;
        }

        if (temp == k2)
        {
            cout << 2 << " ";
            continue;
        }

        if (grupos.find(n+temp) == k1)
        {
            grupos.join(temp,k2);
            
            cout << 2 << " ";

            continue;
        }
        else
        {
            grupos.join(temp,k1);
            grupos.join(n+temp,k2);
            
            cout << 1 << " ";

            continue;
        }
       
    }
}