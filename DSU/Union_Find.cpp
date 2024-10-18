#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

vector<int> pai;
vector<int> max_dist;

int find(int x)
{
    if (pai[x] == x) return x;

    return pai[x] = find(pai[x]);
}

void join(int a,int b)
{
    int g1 = find(a);
    int g2 = find(b);

    if (g1 == g2) return;


    if (max_dist[g1] > max_dist[g2]) pai[g2] = g1;
    if (max_dist[g1] < max_dist[g2]) pai[g1] = g2;

    if (max_dist[g1] == max_dist[g2])
    {
        pai[g2] = g1; //caso ambos sejam iguais, 1 é pai
        max_dist[g1]++;
    }
}

int main()
{
    int n, q;
    cin >> n >> q;

    pai.resize(n);
    max_dist.resize(n,0);

    for (int i=0;i<n;i++) pai[i] = i;

    int op,a,b;
    while (q--)
    {
        cin >> op >> a >> b;

        if (op)
        {
            cout << (find(a) == find(b)) << endl;
        }
        else
        {
            join(a,b);
        }
    }



}