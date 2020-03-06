#include<bits/stdc++.h>
using namespace std;
string st1;
int arr1[30],arr2[30],num,dp[21][21];
int LCS(int ind1,int ind2)
{
   // cout<<ind1<<"@ "<<ind2<<endl;
    if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];

    if(ind1==num+1 || ind2==num+1)return 0;

   int coun=0;

    if(arr1[ind1]==arr2[ind2]){
          //  cout<<arr1[ind1]<<"  "<<arr2[ind2]<<endl;
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
    int n;
        int flg=0;
    while(getline(cin,st1))
    {
        memset(dp,-1,sizeof(dp));
        int len=st1.size();
        stringstream ss (st1);
        int i=1;
        if(len<=2)
        {
            ss>>num;
            flg=1;
          // cout<<num<<endl;
        }
        else
        {
            while(ss>>n)
            {
                if(flg==1)
                {
                    arr1[n]=i++;
                   // cout<<arr1[i]<<endl;
                }
                else
                {
                    arr2[n]=i++;
                    //cout<<i<<arr2[i]<<endl;
                }

            }
            //for(int i=1;i<=num;i++)printf(" %d ",arr1[i]);
            if(flg==0){
            int res=LCS(1,1);
            printf("%d\n",res);
            }
                flg=0;
        }
    }
}
