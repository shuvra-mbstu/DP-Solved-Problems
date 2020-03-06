#include<bits/stdc++.h>
using namespace std;
string st1,st2;

int len1,len2,dp[30][30];

int LCS(int ind1, int ind2)
{
    if(ind1==(len1) )return (len2-ind2);
    if( ind2==(len2))return(len1-ind1);
    if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];

    int ret=3000,ret1=3000,ret2=3000,ret3=3000;

    if(st1[ind1]==st2[ind2])
    {
        ret = LCS(ind1+1,ind2+1);
    }
    else
    {
        ret1 = 1+LCS(ind1+1,ind2+1);
        ret2 = 1+LCS(ind1+1,ind2);
        ret3 = 1+LCS(ind1,ind2+1);
    }
    return dp[ind1][ind2] = min(ret,min(ret1,min(ret2,ret3)));
}
void printLCS(int i,int j)
{
    if( i==len1 )
    {
        if(j==len2) return;
        else
        {
            while(j!=len2)
            {
                cout<<'I'<<st2[j];
                if((j+1)<=9)
                {
                    cout<<'0';
                }
                cout<<j+1;
                j++;
            }
        }
        return;
    }
    if(j==len2)
    {
        if(i==len1)return;
        else
        {
            while(i!=len1)
            {
//             cout << "---> 1 ";
                cout<<'D'<<st1[i];
                if((j+1)<=9)
                {
                    cout<<'0';
                }
                cout<<j+1;
                i++;
            }
            return;
        }
    }

    if(st1[i]==st2[j])
    {
        printLCS(i+1,j+1);
    }
    else
    {
        int ret1=1+LCS(i+1,j+1);
        int ret2=1+LCS(i+1,j);
        int ret3=1+LCS(i,j+1);
        //   cout<<i<<" "<<j<<endl;
        if(dp[i][j]==ret1)
        {
            cout<<'C'<<st2[j];
            if((j+1)<=9)
            {
                cout<<'0';
            }
            cout<<j+1;
            printLCS(i+1,j+1);
        }
        else if(dp[i][j]==ret2)
        {
//             cout << "---> 2 ";
            cout<<'D'<<st1[i];
            if((j+1)<=9)
            {
                cout<<'0';
            }
            cout<<j+1;
            printLCS(i+1,j);
        }
        else if(dp[i][j]==ret3)
        {
            cout<<'I'<<st2[j];
            if((j+1)<=9)
            {
                cout<<'0';
            }
            cout<<j+1;
            printLCS(i,j+1);
        }
    }
}
int main()
{
    while( cin>>st1)
    {
        if(st1=="#")break;

        memset(dp,-1,sizeof(dp));
        len1=st1.size();
        cin>>st2;
        len2=st2.size();
        int res=LCS(0,0);
        printLCS(0,0);
        printf("E\n");
    }
    return 0;
}
