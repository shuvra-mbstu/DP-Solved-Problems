#include<bits/stdc++.h>
using namespace std;
long long int arr[5002],num,val;
//long long int sum[5002];
priority_queue<long long int> sp;
int main()
{
  long long int sum, res,coun=0;

     while(scanf("%lld",&num)!=EOF)
     {
          if(num==0)
               break;

        sum=0;
        res=0;
        coun=0;
          for(int i=0;i<num;i++)
          {
               scanf("%lld",&val);
               val=val*-1;
               sp.push(val);
          }
         while(!sp.empty())
         {
             // sp.reverse();
              sum=sp.top();
              sp.pop();

              if(!sp.empty()){
              res=sp.top();
              sp.pop();
              }
              coun=coun+res+sum;
              if(!sp.empty())
              sp.push(sum+res);

             // cout<<sum<<"  "<<res<<"  "<<sum+res<<endl;
         }
          printf("%lld\n",-1*(coun));
     }
}
