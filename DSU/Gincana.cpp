#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

vector<int> pais;
vector<int> max_dist;

int grupos;

int find(int x)
{
    if (pais[x] == x) return x;

    return pais[x] = find(pais[x]);
}

void join(int a, int b)
{
    int ga = find(a);
    int gb = find(b);

    if (ga == gb) return;

    grupos--;

    if (max_dist[ga] > max_dist[gb]) pais[gb] = ga;
    if (max_dist[gb] > max_dist[ga]) pais[ga] = gb;

    if (max_dist[ga] == max_dist[gb])
    {
        pais[gb] = ga;
        max_dist[ga]++;
    }
}


int main()
{
    int n,m;
    cin >> n >> m;

    grupos = n;
    pais.resize(n+1);
    max_dist.resize(n+1,0);

    for (int i=0;i<=n;i++) pais[i] = i;

    int a,b;
    while (m--)
    {
        cin >> a >> b;

        join(a,b);
    }

    cout << grupos;

}