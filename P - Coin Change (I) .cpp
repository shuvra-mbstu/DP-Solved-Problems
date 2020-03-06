#include<bits/stdc++.h>
//#define mx 1007
#define m 100000007
#define mx 1002
using namespace std;
long long int arr[52],val[52];
long long int dp[21][52][mx],total,value;
long long int fun(long long int state,long long int ind, long long int sum)
{
   //cout<<"ind "<<arr[ind]<<" sm  "<<sum<<" st "<<state<<" res "<<total<<endl;


    if(sum==0) return 1;

    if(ind==value)return 0;

    if(sum<0)  return 0;

long long int res1,res2;

    if(dp[state][ind][sum]!=-1)
        return dp[state][ind][sum];

   if(state!=0)
   {
     long long int a=state-1;
    res1=fun(a,ind,sum-arr[ind]);
    res2=fun(val[ind+1],ind+1,sum);
   }
    else
    {
        res1=0;
        res2=fun(val[ind+1],ind+1,sum);
    }

    total=(res1+res2)%m;
  //  cout<<res1<<" #"<<res2<<" @"<<total<<endl;
    dp[state][ind][sum]=total;
    return total;
}
int main()
{
  long long int num,test,cas=1;

  scanf("%lld",&test);
   while(test--)
   {
       long long int res=0;
        memset(dp,-1,sizeof(dp));
       scanf("%lld%lld",&value,&num);
       for(int i=0; i<(value);i++)
       {
           scanf("%lld",&arr[i]);
       }
       for(int i=0; i<(value);i++)
       {
           scanf("%lld",&val[i]);
       }
      res= fun(val[0],0,num);

       printf("Case %lld: %lld\n",cas++,res);
   }
   return 0;
}
