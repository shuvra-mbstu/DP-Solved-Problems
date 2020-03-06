#include<bits/stdc++.h>
using namespace std;
  int len1,len2,dp[102][102],arr1[102],arr2[102];

int LCS(int ind1,int ind2)
{
   // cout<<ind1<<"@ "<<ind2<<endl;
    if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];

    if(ind1==len1 || ind2==len2)return 0;

   int coun=0;

    if(arr1[ind1]==arr2[ind2]){
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
    int cas=0;
    while(scanf("%d%d",&len1,&len2)==2)
    {
    memset(dp,-1,sizeof(dp));

        if(len1==0 && len2==0)break;

        for(int i=0;i<len1;i++)
        {
            scanf("%d",&arr1[i]);
        }
         for(int i=0;i<len2;i++)
        {
            scanf("%d",&arr2[i]);
        }
       int res =LCS(0,0);
        printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",++cas,res);
    }
}
