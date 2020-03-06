#include<bits/stdc++.h>
using namespace std;
string s1, st;
int i,dp[203][203],sum,arr[300];
int fun(int ind,int num1)
{
     int diff;
     if(dp[ind][num1]!=-1)return dp[ind][num1];

          int num2=sum-num1;
               diff=abs(num2-num1);
     if(ind==i)
     {
          return diff;
     }
     int res1=min(diff,fun(ind+1,num1+arr[ind]));
     int res2=min(diff,fun(ind+1,num1));
     int res=min(res1,res2);
     dp[ind][num1]=res;
     return res;
}
int main()
{
     int test;
     char C;
     scanf("%d",&test);
     getchar();
     while(test--)
     {
          memset(dp,-1,sizeof(dp));
           int ress;
          C=' ';
          i=0;
          sum=0;
          while(C==' ')
          {
              // cout<<"@ "<<C<<endl;
               scanf("%d",&arr[i++]);
               scanf("%c",&C );
              // getchar();
               sum+=arr[i-1];
          }
          ress=fun(0,0);
          if(ress==0)
               printf("YES\n");
          else
               printf("NO\n");
     }
}
