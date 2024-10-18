#include <bits/stdc++.h>
using namespace std;

int dp[100000];

class grafo
{
public:
    int size;
    vector<int> *container;

    grafo(int arg)
    {
        size = arg;
        container = new vector<int>[size];
    }

    void add(int de,int para)
    {
        container[de].push_back(para);
    }

    int solve(int node)
    {
        if (dp[node] != -1) return dp[node];
        if (node == size-1) return 1;

        int res = 0;

        for (int v : container[node])
        {
            res += solve(v);
            res %= 1000000007;
        }

        dp[node] = res;
        return res;
    }
};

int main()
{
    memset(dp,-1,sizeof(dp));
    int n,m;
    cin >> n >> m;

    grafo meug(n);

    int a,b;
    while (m--)
    {
        cin >> a >> b;
        meug.add(--a,--b);
    }

    cout << meug.solve(0);
}