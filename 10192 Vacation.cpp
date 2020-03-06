#include<bits/stdc++.h>
using namespace std;

    string st1,st2;

    vector<char>vt1,vt2;

    int len1,len2,dp[107][107];

int LCS(int ind1, int ind2)
{
    if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];

    if(ind1==len1 || ind2==len2)return 0;

    int coun=0;

    if(vt1[ind1]==vt2[ind2]){
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
    int cas=0;
    while(getline(cin,st1))
    {
        if(st1=="#")break;

        getline(cin,st2);
        memset(dp,-1,sizeof(dp));

        len1=st1.size();
        for(int i=0;i<len1;i++)
        {
            if( (st1[i]>='A'&& st1[i]<='Z')  ||    (st1[i]>='a'&&st1[i]<='z')  ||    (st1[i]==' ')   ||   (st1[i]>='0'&&st1[i]<='9'))
            {
                vt1.push_back(st1[i]);
            }
        }
        len2=st2.size();
         for(int i=0;i<len2;i++)
        {
            if( (st2[i]>='A'&& st2[i]<='Z')     || (st2[i]>='a'&&st2[i]<='z')    ||  (st2[i]==' ')   ||  (st2[i]>='0'&&st2[i]<='9')  )
            {
                vt2.push_back(st2[i]);
            }
        }
        len1=vt1.size();
        len2=vt2.size();
        int res=LCS(0,0);
            printf("Case #%d: you can visit at most %d cities.\n",++cas,res);
            vt1.clear();
            vt2.clear();
    }
}

