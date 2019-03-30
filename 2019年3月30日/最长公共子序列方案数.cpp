#include<bits/stdc++.h>
#define mod 100000000
using namespace std;
const int maxn=5007;
char s1[maxn],s2[maxn];
int dpl[maxn][maxn];
int dpn[2][maxn];

int main()
{

    scanf("%s",s1+1);//
    scanf("%s",s2+1);
    int len1=strlen(s1+1)-1;
    int len2=strlen(s2+1)-1;

    dpl[1][1]=s1[1]==s2[1]?1:0;
    for(int k=0;k<=len2;k++)dpn[0][k]=1;
    dpn[1][0]=1;
    int cur=1;
    int last=0;
    for(int i=1;i<=len1;i++)
    {
         for(int j=1;j<=len2;j++)
        {
            dpn[cur][j]=0;
            if(s1[i]==s2[j]) dpl[i][j]=dpl[i-1][j-1]+1;
            else
            dpl[i][j]=max(dpl[i-1][j],dpl[i][j-1]);

            if(s1[i]==s2[j])dpn[cur][j]+=dpn[last][j-1];

            if(dpl[i][j-1]==dpl[i][j])dpn[cur][j]+=dpn[cur][j-1];
            if(dpl[i-1][j]==dpl[i][j])dpn[cur][j]+=dpn[last][j];
            if(dpl[i][j]==dpl[i-1][j-1]) dpn[cur][j]-=dpn[last][j-1];

            dpn[cur][j]=(dpn[cur][j]+mod)%mod;

        }
        cur^=1;
        last^=1;
    }

    printf("%d\n%d",dpl[len1][len2],dpn[last][len2]);
    return 0;
}