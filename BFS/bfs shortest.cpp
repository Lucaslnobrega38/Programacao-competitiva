#include <bits/stdc++.h>
using namespace std;

class grafo
{
    int size;
    list<int> *container;

    public:

    grafo(int arg)
    {
        size = arg;
        container = new list<int>[size];
    }

    void adiciona(int de, int para, bool undir = true)
    {
        container[de].push_back(para);

        if (undir)
        {
            container[para].push_back(de);
        }
    }


    void bfs(int de,int para)
    {
        vector<bool> visitados(size,false);
        queue<int> fila;
        vector<int> distancias_de(size,-1);
        vector<int> antes_de(size,-1);

        fila.push(de);
        visitados[de] = true;
        distancias_de[de] = 0;

        while (!fila.empty())
        {
            int frente = fila.front();

            for (int viz : container[frente])
            {
                if (!visitados[viz])
                {
                    fila.push(viz);
                    visitados[viz] = true;
                    antes_de[viz] = frente;
                    distancias_de[viz] = distancias_de[frente]+1;

                }

            }
            fila.pop();
        }

        for (int i =0;i<size;i++)
        {
            cout << distancias_de[i] << " ";
        }
    }



};

int main()
{
    grafo meug(6);

    meug.adiciona(0,3);
    meug.adiciona(3,5);
    meug.adiciona(5,1);
    meug.adiciona(1,2);
    meug.adiciona(2,4);

    meug.bfs(0,0);

}