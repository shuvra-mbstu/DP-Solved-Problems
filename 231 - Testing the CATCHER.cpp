#include<bits/stdc++.h>
#define mx 1007
using namespace std;

int dp[mx],num,start;
int arr[mx];

int longest(int u)
{
    if(dp[u]!=-1) return dp[u];
    //cout << num << endl;
    int maxi=0,coun=0;

    for(int v=u+1; v<=num; v++)
    {
        //cout << "ok\n";

            if(arr[u]>arr[v])
            {
               // cout<<vt[v][i]<<endl;
            if(longest(v)>maxi)
            {
                maxi=longest(v);
                //dir[u]=v;
            }
        }
    }
    dp[u] = 1+ maxi;

  //cout<<"@"<<u<<" "<<maxi<<" "<<dp[u]<<endl;
    return dp[u];
}

int main()
{
     int i,res,cas=0;
   while(scanf("%d",&num)!=EOF)
   {
     if(num==-1)
          break;

        memset(dp,-1,sizeof(dp));

          arr[1]=num;
          i=2;
     while(num!=-1)
     {
          scanf("%d",&num);
          arr[i++]=num;
        //  cout<<i<<"  "<<arr[i-1]<<endl;
     }
     num=i-2;
     int ma=0;
     //cout<<num<<endl;
     for(int i=1;i<=num;i++){
     res=longest(i);
     if(ma<res)
     {
          ma=res;
     }
     }
        if(cas!=0)printf("\n");
     printf("Test #%d:\n  maximum possible interceptions: %d\n",++cas,ma);
   }
}
