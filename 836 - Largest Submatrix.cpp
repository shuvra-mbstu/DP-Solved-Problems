#include<bits/stdc++.h>
using namespace std;
long long int sum[107],curr;
int arr[107][107];
int fun(int n)
{
    int mx=0;
    sum[0]=0;
    for(int i=1; i<=n; i++)
    {
        // int l=0;
        memset(sum,0,sizeof(sum));
        for(int m=i; m<=n; m++)
        {
            curr=0;
            for(int j=1; j<=n; j++)
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
    int num,res,len,l;
    string st;
    char ch,c;
    scanf("%d",&num);
        getchar();
        getchar();
    while(num--)
    {
        int i=0;
        while(getline(cin,st))
        {
            ++i;
            //getline(cin,ss);
            len=st.size();
            if(i==1)
            {
                l=len;
            }
            if(len==0)
                break;

            for(int j=1; j<=len; j++)
            {
                arr[i][j]=st[j-1]-'0';

                if(arr[i][j]==0)
                    arr[i][j]=-10000;
                //cout<<arr[i][j]<<endl<<len<<endl;

            }
            //  getchar();
        }
       // st.clear();
        //arr[0][0]=0;
        res=fun(l);
        printf("%d\n",res);
        if(num!=0)
            printf("\n");
    }
}
