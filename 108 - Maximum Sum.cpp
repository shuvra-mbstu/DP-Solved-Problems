#include<bits/stdc++.h>
using namespace std;
int arr[107][107],sum[107];
int fun(int n)
{
    int mx=-1000,mxro,mxcol,mxup,mxdown,curr;
    sum[0]=0;
    for(int i=1;i<=n;i++)
    {
       // int l=0;
                memset(sum,0,sizeof(sum));
        for(int m=i;m<=n;m++){
        curr=0;
        for(int j=1;j<=n;j++)
        {
            sum[j]=sum[j]+arr[j][m];
           // cout<<"#"<<sum[j]<<"    "<<arr[j][m]<<endl;
            curr=curr+sum[j];
            if(curr>mx)
            {
                mx=curr;

            }
            if(curr<0)
                curr=0;

              // cout<<curr<<" MX "<<mx<<endl;
        }
    }
}
    return mx;
}
int main()
{
    int num,res;
    scanf("%d",&num);
    for(int i=1;i<=num;i++)
    {
        for(int j=1;j<=num;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    arr[0][0]=0;
    res=fun(num);
    printf("%d\n",res);
}
