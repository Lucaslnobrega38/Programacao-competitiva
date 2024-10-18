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
        arr.resize(size,0);
    }

    void add(int val,int index)
    {
        while (index < size)
        {
            arr[index] += val;
            index += (index & (-index));
        }
    }

    int sum(int r)
    {
        int res = 0;

        while (r > 0)
        {
            res += arr[r];
            r -= (r & (-r));
        }

        return res;
    }

    int sump(int r)
    {
        return sum(r)-sum(r-1);
    }
};

int main()
{
    int t;
    cin >> t;

    int m,r;

    int qry;
    while (t--)
    {
        cin >> m >> r;
        fenwick tree(m+1);
        bool mat[m+1][m+1];
        memset(mat,0,sizeof(mat));

        for (int i=1;i<=m;i++)
        {
            tree.add(i-1,i);
        }

        for (int i=1;i<= m;i++)
        {
            for (int j=0;j<i;j++)
            {
                mat[i][j] = true; // j está abaixo de i
            }
        }

        int last = -1;

        while (r--)
        {
            cin >> qry;
            int temp =  tree.sump(qry);
            cout << temp << " ";

            if (last != qry)
            {
                tree.add(-temp,qry); // tirar o 1
                int index;
                for (int i=1;i<=m;i++)
                { 
                    if (mat[qry][i])
                    {
                        tree.add(1,i);
                        mat[qry][i] = false;
                    }
                }

                for (int i=1;i<=m;i++)
                {
                    mat[i][qry] = true;
                }

 
            }

            last = qry;
        }

        cout << "\n";
    }
}