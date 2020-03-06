#include<bits/stdc++.h>
using namespace std;
# define mx 107
#define endd -999999
int arr[109],num,maxi=1,dp[mx];
int MAX(int ind)
{
     if(dp[ind]!=-1)return dp[ind];

     if(ind==(num-1))return arr[ind];

     int res1=maxi*arr[ind]*MAX(ind+1);
     int res2=(maxi*MAX(ind+1));

     maxi=max(res1,res2);
     dp[ind]=maxi;
     return maxi;
}
int main()
{
      while(scanf("%d",&num)!=EOF)
      {
           memset(dp,-1,sizeof(dp));
           int i=0,res;
           while(num!=endd)
           {
                arr[i++]=num;
                scanf("%d",&num);
           }
           num=i-1;
           res=MAX(0);
           printf("%d\n",res);
      }
}
