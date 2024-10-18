class Solution {
public:

    int dp[41][1024];

    int numberWays(vector<vector<int>> &people,int etapa,int bitmask,int pessoas)
{
    if (dp[etapa][bitmask] != -1) return dp[etapa][bitmask];

    if (bitmask == (1<<pessoas)-1) return 1;

    if (etapa >= 40) return 0;

    int size = people[etapa].size();
    
    int pessoa;
    int res = 0;

    for (int i=0;i<size;i++)
    {
        pessoa = people[etapa][i];

        if ((bitmask & (1<<pessoa)) == 0)
        {
            res += numberWays(people,etapa+1,bitmask bitor (1<<pessoa),pessoas);
            res %= 1000000007;
        }

    }
    res += numberWays(people,etapa+1,bitmask,pessoas);

    res = res%(1000000007);

    dp[etapa][bitmask] = res;
    return res;
}

int numberWays(vector<vector<int>> hats)
{
    vector<vector<int>> peoplearg(40,vector<int>());
    memset(dp,-1,sizeof(dp));
    for (int pessoa=0;pessoa<hats.size();pessoa++)
    for (int i=0;i<hats[pessoa].size();i++)
    {
        peoplearg[hats[pessoa][i]-1].push_back(pessoa);
    }

    
 
    

    return numberWays(peoplearg,0,0,hats.size());
}

};