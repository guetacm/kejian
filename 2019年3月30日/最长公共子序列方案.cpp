#include <bits/stdc++.h>
using namespace std;
const int maxn=5007;
string dp[maxn][maxn];
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    s1=" "+s1;
    s2=" "+s2;
    for(int i=1;i<s1.size();i++)
        for(int j=1;j<s2.size();j++)
            if(s1[i]==s2[j])
                dp[i][j]=dp[i-1][j-1]+s1[i];
            else
                dp[i][j]=dp[i-1][j].size()>dp[i][j-1].size()?dp[i-1][j]:dp[i][j-1];
                //dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    cout<<dp[s1.size()-1][s2.size()-1];
    return 0;
}
