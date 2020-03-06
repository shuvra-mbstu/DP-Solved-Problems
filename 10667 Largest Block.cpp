#include<bits/stdc++.h>
using namespace std;
long long int sum[107],curr;
int arr[107][107];
int fun(int n)
{
   //  cout<<n<<endl;
    int mx=0;

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
           //    cout<<curr<<" MX "<<mx<<endl;
            if(curr<0)
                curr=0;

        }
        }
    }
    return mx;
}
int main()
{
    int num,ro1,ro2,col1,col2,res,test,qur;
    scanf("%d",&test);
    while(test--){
          scanf("%d%d",&num,&qur);
         // memset(arr,1,num);
                   //  cout<<num<<"  "<<qur<<endl;
                   for(int i=1;i<=num;i++)
{
     for(int j=1;j<=num;j++)
     {
         // if(arr[i][j]==0)
               arr[i][j]=1;
     }
}
           while(qur--){
        scanf("%d%d%d%d",&ro1,&ro2,&col1,&col2);
       // cout<<ro1<<" "<<col1<<" "<<ro2<<" "<<col2<<endl;
    for(int i=ro1;i<=col1;i++)
    {
        for(int j=ro2;j<=col2;j++)
        {
           //  cout<<arr[i][j]<<" "<<i<<" "<<j<<endl;
           // scanf("%d",&arr[i][j]);
                arr[i][j]=-10000;
                           //  cout<<arr[i][j]<<endl;
        }
    }
}

          // cout<<num<<endl;
    //arr[0][0]=0;
    res=fun(num);
    printf("%d\n",res);
}
}
