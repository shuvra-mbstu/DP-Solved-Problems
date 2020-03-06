
#define mx 30002
#include<bits/stdc++.h>
using namespace std;
long long int arr[]={5,10,20,50,100,200,500,1000,2000,5000,10000};
long long int dp[12][mx],total;
long long int fun(long long int ind, long long int sum)
{
    //sum=sum/10;
   // cout<<ind<<"  "<<sum<<endl;
    if(sum==0) return 1;

    if(sum<0)  return 0;

    if(ind==11)  return 0;

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
  double num;
  //long long int val;
    memset(dp,-1,sizeof(dp));

   while(scanf("%lf",&num)!=EOF)
   {
       if(num==0.0)break;

      int val=(num*100);
       int a= val%10;
       if(a%5 != 0){
        val=val+1;
       }
      // cout<<val<<endl;
      long long int res= fun(0,val);

       printf("%6.2lf%17lld\n",num,res);
   }
   return 0;
}
