#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

vector<int> pai;
vector<int> peso;
vector<int> qtd;

int find(int x)
{
    if (pai[x] == x) return x;

    return pai[x] = find(pai[x]);
}

void join(int a,int b)
{
    int ga = find(a);
    int gb = find(b);

    if (ga == gb)
    {
        cout << qtd[ga] << endl;
        return;
    }

    if (peso[ga] > peso[gb])
    {
        pai[gb] = ga;
        qtd[ga] += qtd[gb];
        cout << qtd[ga] << endl;
        return;
    }

    if (peso[gb] > peso[ga])
    {
        pai[ga] = gb;
        qtd[gb] += qtd[ga];
        cout << qtd[gb] << endl;
        return;
    }

    pai[gb] = ga;
    peso[ga]++;
    qtd[ga] += qtd[gb];
    cout << qtd[ga] << endl;

    
}

int main()
{
    int t;
    cin >> t;

    int f;

    string temps;

    while (t--)
    {
        int lindex = 1;
        cin >> f;

        vector<string> arr;
        map<string,int> dict;

        for (int i=0;i<f*2;i++)
        {
            cin >> temps;
            arr.push_back(temps);

            if (dict[temps] == 0)
            {
                dict[temps] = lindex;
                lindex++;
            }
        }

        pai.resize(lindex);
        peso.resize(lindex);
        qtd.resize(lindex);

        for (int i=0;i<lindex;i++)
        {
            pai[i] = i;
            peso[i] = 0;
            qtd[i] = 1;
        }

        for (int i=0;i<f*2;i+=2)
        {
            join(dict[arr[i]],dict[arr[i+1]]);
        }
    }
}