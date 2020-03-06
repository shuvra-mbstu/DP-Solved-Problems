#include<bits/stdc++.h>
using namespace std;

   int arr[1007],val[1007];

    int len1,len2,dp[1007][1007];

int LCS(int ind1, int ind2)
{
    if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];

    if(ind1==len1 || ind2==len2)return 0;

    int coun=0;

    if(st1[ind1]==st2[ind2]){
        coun= LCS(ind1+1,ind2+1)+1;
    }
    else
    {
        int res1=LCS(ind1+1,ind2);
        int res2= LCS(ind1,ind2+1);
        coun=max(res1,res2);
    }
    dp[ind1][ind2]=coun;
    return coun;
}

int main()
{
     int i=0;
    while()
    {
        getline(cin,st2);
        memset(dp,-1,sizeof(dp));

        len1=st1.size();
        len2=st2.size();
        int res=LCS(0,0);
            printf("%d\n",res);
    }
}
