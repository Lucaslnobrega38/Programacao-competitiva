#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << 1;
        return 0 ;
    }



    vector<int> seq;

    for (int i=0;i<n;i++)
    {
        int temp;
        cin >> temp;
        seq.push_back(temp);
    }
    seq.push_back(25);

    int best = 0;
    int x, y;
    for (int i=1;i <= n;i++)
    {
        for (int j=1;j <= n;j++)
        {
            if (i == j) continue;

            int select[2];

            select[0] = i;
            select[1] = j;

            int bit = 0;
            int score = 0;

            for (int k=0;k<n;k++)
            {
                int check = seq[k];

                if (check == select[bit])
                {
                    score++;
                    bit ^= 1;
                }

                if (check == select[(~bit)])
                {
                    if (score > best){best = score;x = i;y=j;}
                    score = 1;
                    continue;
                }

                if (score > best){best = score;}


            }

        }
    }

    cout << best;
}