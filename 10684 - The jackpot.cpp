#include<bits/stdc++.h>
using namespace std;
#define mx 10007
int main()
{
    int arr[mx],num,sum,mxi;
    while(scanf("%d",&num)!=EOF)
    {
        int flg=0;
        sum=0;
        mxi=-100000;
        if(num==0)
        {
            break;
        }
        for(int i=0;i<num;i++)
        {
            scanf("%d",&arr[i]);
            sum+=arr[i];
            if(arr[i]>0)
            {
                flg=1;
            }
            if(mxi<sum)
            {
                mxi=sum;
            }
            if(sum<0)
            {
                sum=0;
            }
        }
        if(flg==0)
        {
            printf("Losing streak.\n");
        }
        else
            printf("The maximum winning streak is %d.\n",mxi);
    }
}
