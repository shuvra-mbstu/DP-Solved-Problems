#include<bits/stdc++.h>
using namespace std;
string st1,st2;


    int len1,len2,dp[1000][1002],val1,val2;

int LCS(int ind1, int ind2)
{
                  //  cout<<st2[ind1]<<" "<<st1[ind2]<<endl;

    if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];

    if(ind1==(len1) )return 0;

    if( ind2==(len2))return 0;

    int coun=0;

    if(st1[ind1]==st2[ind2]){
              // cout<<st2[ind1]<<" "<<st1[ind2]<<endl;
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
     int test,mx=0;
     scanf("%d",&test);
     getchar();
     while(test--)
     {
          mx=0;
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

               printf("%d\n",ans);
     }
}
