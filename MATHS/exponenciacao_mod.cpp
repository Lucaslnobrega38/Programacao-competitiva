#include <bits/stdc++.h>
using namespace std;

#define mod 1e9+7

long long expo_mod(int a,int b)
{
    int res = 1;
    
    while (b)
    {
	if (b&1)
	{
	    res *= a;
	}
	a *= a;
	
	a %= mod;
	res %= mod;

	b >>= 1;
    }
}