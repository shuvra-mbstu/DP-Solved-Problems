#define mx 8000
#include<bits/stdc++.h>
using namespace std;
int arr[]={1,5,10,25,50};
int dp[6][mx],total;
int fun(int ind, int sum)
{
  //  cout<<ind<<"  "<<sum<<endl;
    if(sum==0) return 1;

    if(sum<0)  return 0;

    if(ind==5)  return 0;

    if(dp[ind][sum]>=0)
        return dp[ind][sum];

    int res1=fun(ind,sum-arr[ind]);
    int res2=fun(ind+1,sum);
    total=res1+res2;
  //  cout<<res1<<" #"<<res2<<" @"<<total<<endl;
    dp[ind][sum]=total;
    return total;
}
int main()
{
   int num;
    memset(dp,-1,sizeof(dp));

   while(scanf("%d",&num)!=EOF)
   {
       int res= fun(0,num);
       printf("%d\n",res);
   }
   return 0;
}
