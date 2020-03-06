#include<bits/stdc++.h>
using namespace std;
#define mx 1000000
long  long int dp[107][107],num,k;
long long int fun(long long int ind, long long int sum)
{
    long long int res=0;
    if(ind==(k))
    {
        if(sum==num)return 1;
        else
            return 0;
    }

    if(sum>num)return 0;

    if(dp[ind][sum]!=-1)return dp[ind][sum];

    for(long long int i=0; i<=num; i++)
    {
        res+=(fun(ind+1,i+sum))%mx;
    }
    dp[ind][sum]=res;
    //cout<<ind<<"  "<<sum<<"  "<<res<<endl;
    return res;
}
 int main()
{
    while(scanf("%lld%lld",&num,&k)!=EOF)
    {
        if(num==0 && k==0)break;

        memset(dp,-1,sizeof(dp));

        long long int ress=fun(0,0)%mx;
        printf("%lld\n",ress);
    }
}
