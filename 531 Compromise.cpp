#include<bits/stdc++.h>
using namespace std;

string st1,st2;

int len1,len2,dp[100][107],wrd1,wrd2;
vector<string> vt1,vt2;

int LCS(int ind1, int ind2)
{
    if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];

    if(ind1==wrd1 || ind2==wrd2)return 0;

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
    dp[ind1][ind2]=coun;
    return coun;
}
string ans="";
void priLCS(int i,int j)
{
     //cout<<wrd1<<endl<<wrd2<<endl;
    if(i==wrd1 || j==wrd2)
    {
         return;
    }
     if(vt1[i]==vt2[j]){
              // cout<<vt1[i]<<endl;
              if(ans!="")
              {
                   ans+=" ";
              }
               ans+=vt1[i];

               priLCS(i+1,j+1);
     }
     else
     {
          if(dp[i+1][j]>dp[i][j+1])priLCS(i+1,j);
          else
               priLCS(i,j+1);
     }
}
int main()
{
    int cas=0;
    string s,s2;
    while(cin>>st1)
    {
        vt1.clear();
        vt2.clear();

        memset(dp,-1,sizeof(dp));

        while(st1!="#")
        {
            len1=st1.size();
            s="";
            for(int i=0; i<len1; i++)
            {
                if(st1[i]>='a'&&st1[i]<='z')
                {
                    s=s+st1[i];
                }
            }
            vt1.push_back(s);
            cin>>st1;
          //cout<<s<<endl;
        }
        cin>>st2;
       // cout<<st2<<endl;
        while(st2!="#")
        {
            len2=st2.size();
            s2="";
            for(int i=0; i<len2; i++)
            {
                if(st2[i]>='a'&&st2[i]<='z')
                {
                    s2=s2+st2[i];
                }
            }
            vt2.push_back(s2);
            cin>>st2;
            //cout<<s2<<endl;
        }
        wrd1=vt1.size();
        wrd2=vt2.size();
        //cout<<wrd1<<endl<<wrd2<<endl;
        int res=LCS(0,0);
      priLCS(0,0);
      cout<<ans<<endl;
      ans.clear();
    }
}

