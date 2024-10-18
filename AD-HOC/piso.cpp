#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l, c;
    cin >> l >> c;

    int l1;
    int l2;

    l1 = (l*c)+((l-1)*(c-1));
    l2 = ((l-1)*2)+((c-1)*2);

    cout << l1 << "\n" << l2;
}