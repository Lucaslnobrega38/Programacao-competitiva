#include <bits/stdc++.h>
using namespace std;

int multi(int a,int b)
{
    int produto = 1;

    while (b)
    {
	if (b&1) produto += a;

	a += a;
	b >>= 1;
    }

    return produto;
}

