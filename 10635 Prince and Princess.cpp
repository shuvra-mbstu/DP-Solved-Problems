#include<bits/stdc++.h>
using namespace std;


int dp[257][257];
vector<int> vt1,vt2;

int cas=0,test,val,num1,num2,res;
int LCS(int ind1, int ind2)
{
    int a,b;
    if(ind1==(num1+1) || ind2==(num2+1))return 0;

    a=vt1[ind1];
    b=vt2[ind2];
   // cout<<a <<"   "<<b<<endl;
    if((dp[a][b])!=-1)return dp[a][b];

    int coun=0;

    if(vt1[ind1]==vt2[ind2])
    {
        coun= LCS(ind1+1,ind2+1)+1;
    }
    else
    {
        int res1=LCS(ind1+1,ind2);
        int res2= LCS(ind1,ind2+1);
        coun=max(res1,res2);
    }
    dp[a][b]=coun;
    return coun;
}
int main()
{
    string s;
    scanf("%d",&test);

    while(test--)
    {
        scanf("%d%d%d",&val,&num1,&num2);

        memset(dp,-1,sizeof(dp));
        vt1.clear();

        for(int i=0; i<=(num1); i++)
        {
            scanf("%d",&res);
            vt1.push_back(res);
            //int j=i-1;
            //cout<<s<<endl;
        }
        vt2.clear();
        for(int i=0; i<=(num2); i++)
        {
            scanf("%d",&res);
            vt2.push_back(res);
            //int j=i-1;
            //cout<<s<<endl;
        }

        // cout<<wrd2<<endl;
        int res=LCS(0,0);
        printf("Case %d: %d\n",++cas,res);

    }
}
