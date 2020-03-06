#include<bits/stdc++.h>
using namespace std;
struct arr
{
    int wght,iq;

} arr1[5007];
int dir[5009],dp[5003],num,i;

int longest(int u)
{
    //cout<<"@"<<u<<endl;
    if(dp[u]!=-1) return dp[u];
    //cout << num << endl;
    int maxi=0,coun=0;

    for(int v=0; v<i; v++)
    {
        //  cout << "ok\n";

        coun=0;
        if(((arr1[v].wght<arr1[u].wght) && (arr1[v].iq<arr1[u].iq)) ||((arr1[v].iq<arr1[u].wght) && (arr1[v].wght<arr1[u].iq)))
        {
            // cout<<"w8"<<arr1[v].wght<<"   "<<arr1[u].wght<<"\n iq "<<arr1[v].iq<<"   "<<arr1[u].iq<<endl;

            if(longest(v)>maxi)
            {
                maxi=longest(v);
                dir[u]=v;
            }
        }
    }

    dp[u] = 1+ maxi;
    return dp[u];
}
void solution(int start)
{
    while(dir[start]!=-1)
    {
        printf("%d\n",start+1);
        start=dir[start];
    }
    printf("%d\n",start + 1);
}
int main()
{
    int num1,num2,val;

    cin>>val;
    for(int j=0;j<val;j++){
    scanf("%d%d",&num1,&num2);

        arr1[j].wght=num1;
        arr1[j].iq=num2;
        //  cout<<arr1[i-1].wght<<"  "<<arr1[i-1].iq<<endl;
    }
    i=val;
    memset(dir,-1,sizeof(dir));
    memset(dp,-1,sizeof(dp));
    int res=0,node;
    for(int j=0; j<i; j++)
    {
        int sta=longest(j);
        if(sta>res)
        {
            res=sta;
            node=j;
        }
    }
    // memset(dp,-1,sizeof(dp));
    // memset(dir,-1,sizeof(dir));
    // res=longest(3);
    printf("%d\n",res);
   // solution(node);
}
