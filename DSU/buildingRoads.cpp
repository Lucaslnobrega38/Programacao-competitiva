#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

vector<int> pai;
int grupos;

int find(int x)
{
    if (pai[x] == x) return x;
    

    return pai[x] = find(pai[x]);
}

pair<int,int> join(int a,int b)
{
    int ga = find(a);
    int gb = find(b);

    if (ga == gb)
    {
        return {0,0};
    }

    pai[gb] = ga;
    grupos--;

    return {ga,gb};
}

int main()
{
    int n,m;
    cin >> n >> m;

    pai.resize(n+1);
    grupos = n;

    for (int i=1;i<=n;i++) pai[i] = i;

    int a,b;
    for (int i=0;i<m;i++)
    {
        cin >> a >> b;
        join(a,b);
    }

    pair<int,int> temp;
    cout << grupos-1 << endl;
    for (int i=2;i<=n;i++)
    {
        temp = join(1,i);
        if (temp.first != 0)
        {
            cout << 1 << " " << i << endl;
        }
    }

}