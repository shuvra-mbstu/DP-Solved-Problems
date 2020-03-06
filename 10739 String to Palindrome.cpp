#include<bits/stdc++.h>
using namespace std;
string st1,st2;


    int len1,len2,dp[1003][1002],val1,val2;

int LCS(int ind1, int ind2)
{
                  //  cout<<st2[ind1]<<" "<<st1[ind2]<<endl;

    if(ind1==(len1) )return (len2-ind2);

    if( ind2==(len2))return(len1-ind1);

    if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];


    int ret=3000,ret1=3000,ret2=3000,ret3=3000;

    if(st1[ind1]==st2[ind2])
    {
       ret = LCS(ind1+1,ind2+1);
    }
    else
    {
        ret1 = 1+LCS(ind1+1,ind2+1);
        ret2 = 1+LCS(ind1+1,ind2);
        ret3 = 1+LCS(ind1,ind2+1);
    }

    return dp[ind1][ind2] = min(ret,min(ret1,min(ret2,ret3)));
}

int main()
{
     int test,cas=0;
     scanf("%d",&test);
     getchar();
     while(test--)
     {
          memset(dp,-1,sizeof(dp));
          getline(cin,st1);
            len1=st1.size();
            len2=len1;
          st2=st1;

                     //val1=i+1;
                     //val2=i+1;
                     reverse(st2.begin(),st2.end());
                 //  cout<<st2<<"  "<<st1<<endl;
          int ans=LCS(0,0);

               printf("Case %d: %d\n",++cas,ans/2);
     }
}
