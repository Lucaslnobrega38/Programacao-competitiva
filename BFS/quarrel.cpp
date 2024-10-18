#include <bits/stdc++.h>
using namespace std;

#define ii pair<int,int>

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
        container[para].push_back(de);
    }

    void solve()
    {
        // fila de prioridade não necessária, pois distancias 1.
        int na,nb;
        na = 0; nb = size-1; 

        bool found = false;

        queue<ii> fila;
        fila.push({na,nb});

        vector<vector<ii>> mat(size,vector<ii>(size,{-2,-2}));
        mat[na][nb] = {-1,-1}; 

        while (!fila.empty())
        {
            na = fila.front().first;
            nb = fila.front().second;

            fila.pop();
            if (na == size-1 && nb == 0)
            {
                found = true;
                break;
            }

            for (auto va : container[na])
            for (auto vb : container[nb])
            {

                if (va != vb && mat[va][vb].first == -2)
                {
                    fila.push({va,vb});
                    mat[va][vb] = {na,nb};
                }

            }
        }

        if (found)
        {
            int dist = -1;

            vector<int> p1,p2;

            //na = size -1;
            //nb = 0;

            while(na != -1 && nb != -1)
            {
                ii temp = mat[na][nb];

                
                p1.push_back(na);
                p2.push_back(nb);

                na = temp.first;
                nb = temp.second;

                dist++;

            }

            cout << dist << "\n";

            reverse(p1.begin(),p1.end());
            reverse(p2.begin(),p2.end());

            for (int x : p1)
            {
                cout << x+1 << " ";
            }
            cout << "\n";

            for (int x : p2)
            {
                cout << x+1 << " ";
            }

            return;
        }

        cout << -1;
    }
};

int main()
{
    int n,m;
    cin >> n >> m;

    grafo meug(n);
    int a,b;
    for (int i=0;i<m;i++)
    {
        cin >> a >> b;
        meug.add(a-1,b-1);
    }

    meug.solve();

}