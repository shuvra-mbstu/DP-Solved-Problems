#include<bits/stdc++.h>
using namespace std;
long long int sum[107],curr;
int arr[107][107];
int fun(int n,int l)
{
    int mx=0;
    sum[0]=0;
    for(int i=1;i<=l;i++)
    {
       // int l=0;
                memset(sum,0,sizeof(sum));
        for(int m=i;m<=l;m++){
        curr=0;
        for(int j=1;j<=n;j++)
        {
            sum[j]=sum[j]+arr[j][m];
         //   cout<<"#"<<sum[j]<<"    "<<arr[j][m]<<endl;
            curr=curr+sum[j];
            if(curr>mx)
            {
                mx=curr;
            }
             //  cout<<curr<<" MX "<<mx<<endl;
            if(curr<0)
                curr=0;

        }
        }
    }
    return mx;
}
int main()
{
    int num1,num2,res;
    while(scanf("%d%d",&num1,&num2)==2){
            if(num1==0 && num2==0)
            break;

    for(int i=1;i<=num1;i++)
    {
        for(int j=1;j<=num2;j++)
        {
            scanf("%d",&arr[i][j]);

            if(arr[i][j]==1)
                arr[i][j]=-10000;
            else
                arr[i][j]=1;
        }
    }
    //arr[0][0]=0;
    res=fun(num1,num2);
    printf("%d\n",res);
}
}
