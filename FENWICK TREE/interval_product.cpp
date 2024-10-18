#include <bits/stdc++.h>
using namespace std;

class fenwick
{
public:
    int size;
    vector<int> arr;

    fenwick(int arg)
    {
        size = arg+1;
        arr.resize(size,1);
    }

    void add(int index,int num)
    {
        while (index < size)
        {
            arr[index] *= num;
            index += (index & (-index));
        }
    }

    void update(int index,int num)
    {
        bool correct = false;
        if (arr[index] == 0) correct = true;

        while (index < size)
        {
            if (correct)
                arr[index] = 1;
            arr[index] *= num;
            index += (index & (-index));
        }
    }

    void product(int l,int r)
    {
        int res = product(r)/product(l-1);
        
        if (res == 0){cout << 0;}
        else
        {
            if (res > 0){cout << "+";}
            else{cout << "-";}
        }
    }

    int product(int r)
    {
        int res = 1;
        while (r)
        {
            res *= arr[r];
            r -= (r & (-r));
        }

        return res;
    }
};

int main()
{
    int n,k;
    while(cin >> n >> k)
    {

    cin >> n;
    cin >> k;

    fenwick tree(n);
    vector<int> arr(n);

    for (int i=0;i<n;i++) cin >> arr[i];

    for (int i=0;i<n;i++) tree.add(i+1,arr[i]);
    
    int a,b;
    int ao= 0, bo = 0;
    char opo = 0;
    while (k--)
    {
        char op;
        cin >> op;
        cin >> a >> b;


        if (op == 'P')
        {
            tree.product(a,b);
        }
        else
        {
            int temp = arr[a-1];
            arr[a-1] = b;

            tree.update(a,b);
        }

        ao = a;
        bo = b;
        opo = op;
    }

    cout << endl;

    }
}