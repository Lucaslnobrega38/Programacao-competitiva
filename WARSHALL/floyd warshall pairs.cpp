#include <bits/stdc++.h>
using namespace std;

        // não é necessário um grafo, mas apenas uma matriz de adjacencia contendo
        // todos os elementos e seus respectivos vertices.

class grafo
{
public:

    int size;
    vector< vector<long long> > mat;

    grafo(int arg)
    {
        size = arg;
        mat = vector< vector<long long> >(size, vector<long long>(size, LONG_LONG_MAX));

        // declarados todos os elementos long_long_max, pois não sabe-se a distância
        // dos vértices.

        for (int i=0;i<size;i++)
        {
            mat[i][i] = 0;
        }
        // naturalmente, a distância de um nó para si mesmo é zero. essas posições,
        // na matriz, são as que o indice da linha e da coluna são iguais.
    }

    void add(int de,int para,long long dist, bool undir = false)
    {
        mat[de][para] = dist;
        
        if (undir) mat[para][de] = dist;
    }

    void exibe()
    {
        for (int i=0;i<size;i++)
        {
            for (int j=0;j<size;j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void warshall()
    {
        // o primeiro for seleciona o nó intermediário, enquanto os outros iteram 
        // pela matriz

        for (int intermediario = 0; intermediario<size; intermediario++)
        {
            for (int de=0; de<size;de++)
            {
                for (int para=0; para<size; para++)
                { 
                    if (mat[de][intermediario] == LONG_LONG_MAX || mat[intermediario][para] == LONG_LONG_MAX) continue;

                    if (mat[de][para] > mat[de][intermediario] + mat[intermediario][para])
                    {
                        mat[de][para] = mat[de][intermediario]+mat[intermediario][para];
                    }
                }
            }
        }
    }

};


int main()
{
    grafo meug(4);
    meug.exibe();
    cout << "\n\n\n";
    meug.add(0,2,-2);
    meug.add(1,0,4);
    meug.add(1,2,3);
    meug.add(2,3,2);
    meug.add(3,1,-1);

    meug.exibe();
    cout << "\n\n\n";
    meug.warshall();

    meug.exibe();
    
}