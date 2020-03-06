#define mx 10007
#include<bits/stdc++.h>
using namespace std;
long long int arr[]={1,8,27,64,125,216,343,512,729,1000,1331,1728,2197,2744,3375,4096,4913,5832,6859,8000,9261};
long long int dp[25][mx],total;
long long int fun(long long int ind, long long int sum)
{
  //  cout<<ind<<"  "<<sum<<endl;
    if(sum==0) return 1;

    if(sum<0)  return 0;

    if(ind==21)  return 0;

    if(dp[ind][sum]>=0)
        return dp[ind][sum];

   long long int res1=fun(ind,sum-arr[ind]);
   long long int res2=fun(ind+1,sum);
    total=res1+res2;
  //  cout<<res1<<" #"<<res2<<" @"<<total<<endl;
    dp[ind][sum]=total;
    return total;
}
int main()
{
  long long int num;
    memset(dp,-1,sizeof(dp));

   while(scanf("%lld",&num)!=EOF)
   {
      long long int res= fun(0,num);
       printf("%lld\n",res);
   }
   return 0;
}
