#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

vector<int> pai;
vector<int> peso;
int n;

int find(int x)
{
    if (pai[x] == x) return x;

    return pai[x] = find(pai[x]);
}

void join(int a,int b)
{
    int pa = find(a);
    int pb = find(b);
 
    if (pa == pb) return; // mesmo grupo

    if (peso[pa] > peso[pb]) pai[pb] = pa;
    if (peso[pb] > peso[pa]) pai[pa] = pb;

    if (peso[pa] == peso[pb])
    {
        pai[pa] = pb;
        peso[pb]++;
    }
    return;
}


int main()
{
    cin >> n;

    pai.resize((n*2));
    peso.resize((n*2));

    for (int i=0;i<2*n;i++)
    {
        peso[i] = 0;
        pai[i] = i;
    }

    int op,a,b,temp;
    while (cin >> op >> a >> b)
    {
        if (!(op or a or b)) break;

        switch (op)
        {
            case 1:
                if (find(a) == find(b+n)){cout << -1 << endl;}
                else 
                {
                    join(a,b);
                    join(a+n,b+n);
                }
            break;

            case 2:
                if (find(a) == find(b)){cout << -1 << endl;}
                else
                {
                    join(a,b+n);
                    join(a+n,b);
                }
            break;

            case 3:
                cout << (find(a) == find(b)) << endl;
            break;

            case 4:
                cout << (find(a) == find(b+n)) << endl;
            break;
        }
    }
}