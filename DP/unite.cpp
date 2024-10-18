#include <bits/stdc++.h>
using namespace std;

vector<string> words = 
    {
        "catg",
        "ctaagt",
        "gcta",
        "ttca",
        "atgcatc"
    };

vector<vector<string>> dp = vector<vector<string>>((1<<words.size()),vector<string>((1<<words.size()),"X"));

string unite(string start,string end)
{
    int len1 = start.size();
    int len2 = end.size();

    string res = "111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";

    for (int i=1;i<=min(len1,len2);i++)
    {
        if ( string(start.end()-i,start.end()) == string(end.begin(),end.begin()+i))
        {
            string temp = start + end.substr(i);
            if (temp.size() < res.size()) res = temp;
        }
    }

    if (res != "111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111")
    {
    return res;
    }
    return start+end;
}

std::string aux(vector<string> words,int bitmask,string palavra,int from)
{
    int n = words.size();
    
    if (bitmask == ((1<<n)-1))
    {
        return palavra;
    }
    
    string res = "111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
    
    for (int i=0;i<n;i++)
    {
        if ((bitmask & (1<<i)) == 0)
        {
            string temp = aux(words,bitmask|(1<<i),words[i],i);
            string loc = palavra;

            if (dp[bitmask][from] == "X")
            {
                loc = unite(loc,temp);
            }
            else
            {
                loc = dp[bitmask][from];
                res = loc;
                break;
            }
            
            if (res.size() > loc.size()) res = loc;
            
        }

        
        
    }

    dp[bitmask][from] = res;
    
    return res;
}

string shortestSuperstring(vector<string> words)
{
    return aux(words,0,"",0);
}
int main()
{

    cout << shortestSuperstring(words) << endl << "gctaagttcatgcatc";
    cout << endl << unite("imipra","pratos"); 
}