#include<bits/stdc++.h>
using namespace std;
string st1,st2;
int  num,arr1[10004],arr2[10004];

    int len1,len2,dp[10000][10004],val1,val2;

int LCS(int ind1, int ind2)
{
                  //  cout<<st2[ind1]<<" "<<st1[ind2]<<endl;

    if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];

    if(ind1==(num) )return 0;

    if( ind2==(num))return 0;

    int coun=0;

    if(arr1[ind1]=arr2[ind2]){
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
     int mx=0;
     while(scanf("%d",&num)!=EOF){
    // getchar();
    mx=num-1;
    for(int i=0;i<num;i++)
     {
          memset(dp,-1,sizeof(dp));
          scanf("%d",&arr1[i]);
          arr2[mx]=arr1[i];
         // getline(cin,st1);
            //len1=st1.size();
          //  len2=len1;
       //   st2=st1;
       mx--;
     }
                     //val1=i+1;
                     //val2=i+1;
                 //  cout<<st2<<"  "<<st1<<endl;
          int ans=LCS(0,0);

               printf("%d\n",ans);
     }

}
