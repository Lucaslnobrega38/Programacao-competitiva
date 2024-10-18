#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

vector<int> pai;
vector<int> peso;
int minv = INT_MAX;

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

    if (peso[ga] > peso[gb]) {pai[gb] = ga; return true;}
    if (peso[gb] > peso[ga]) {pai[ga] = gb; return true;}

    pai[gb] = ga;
    peso[ga]++;

    return true;
}

int main()
{
    int count = 1;
    int n,r;
    while (1)
    {
    cin >> n >> r;

    if (n == 0 && r == 0) return 0;

    pai.resize(n+1);
    peso.resize(n+1);

    for (int i=0;i<=n;i++)
    {
        pai[i] = i;
        peso[i] = 0;
    }

    int a,b,d;

    vector<array<int,3>> vertices; // dab

    for (int i=0;i<r;i++)
    {
        cin >> a >> b >> d;
        --d;
        vertices.push_back({d,a,b});
    }

    int s,dd,t;
    cin >> s >> dd >> t;

    sort(vertices.begin(),vertices.end());

    for (int i=r-1;i>=0;i--)
    {
        if (find(s) == find(dd)) break;

        if (join(vertices[i][1],vertices[i][2])) minv = min(minv,vertices[i][0]);
    }

    int q = t/minv;
    if ((t%minv) > 0) q++;

    cout << "Scenario #" << count << endl;
    cout << "Minimum Number of Trips = " << q << endl;
    cout << endl;

    count++;
    minv = INT_MAX;
    }
    
}