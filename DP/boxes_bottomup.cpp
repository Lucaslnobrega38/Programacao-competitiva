#include <bits/stdc++.h>
using namespace std;



typedef struct
{
    int altura;
    int largura;
    int profundidade;

} caixa;

bool comp(caixa a, caixa b)
{
    return (a.altura < b.altura);
}

int main()
{
    int n;
    cin >> n;

    vector<caixa> arr(n);
    vector<int> aux(n);

    for (int i=0;i<n;i++)
    {
        cin >> arr[i].largura;
        cin >> arr[i].profundidade;
        cin >> arr[i].altura;
    }

    sort(arr.begin(),arr.end(),comp);

    for (int i=0;i<n;i++)
    {
        aux[i] = arr[i].altura;
    }

    for (int i=1;i<n;i++)
    {
        for (int j=0;j<i;j++)
        {
            if (arr[i].largura > arr[j].largura && arr[i].profundidade > arr[j].profundidade && arr[i].altura > arr[j].altura)
            {
                aux[i] = max(aux[i],arr[i].altura+aux[j]);
            }
        }
    }

    for (auto x : aux)
    {
        cout << x << " ";
    }






}