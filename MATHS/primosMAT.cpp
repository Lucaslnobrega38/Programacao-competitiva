#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

bool primo(int x)
{
    if (x == 1) return false;

    for (int i=2; (i*i) <= x; i++)
    {
        if (x%i == 0) return false;
    }

    return true;
}

vector<int> divisores(int x)
{
    vector<int> res;

    for (int i=1;(i*i) <= x;i++)
    {
        if (x % i == 0)
        {
            res.push_back(i);

            if (x/i != i)
            res.push_back(x/i);
        }   

    }
    return res;
}

vector<int> fatora(int x)
{
    vector<int> res;

    for (int i=2; i*i <= x; i++)
    {
        while (x%i == 0)
        {
            res.push_back(i);
            x = x/i;
        }

    }

    if (x > 1) res.push_back(x);

    return res;
}

int main()
{
    int x;
    cin >> x;

    cout << primo(x) << endl;
    for (auto i : divisores(x)) cout << i << " ";
    cout << endl;

    for (auto i : fatora(x)) cout << i << " ";
}