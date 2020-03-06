#include<bits/stdc++.h>
using namespace std;

    string st1,st2;

    int len1,len2,dp[1007][1007],wrd1,wrd2;
    vector<string> vt1,vt2;

int LCS(int ind1, int ind2)
{
    if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];

    if(ind1==wrd1 || ind2==wrd2)return 0;

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
     string s;
    while(getline(cin,st1))
    {
        getline(cin,st2);
        memset(dp,-1,sizeof(dp));

        len1=st1.size();
        len2=st2.size();
        if(len1==0 || len2==0)
        {
             printf("%2d. Blank!\n",++cas);
        }
        else{
               for(int i=0;i<len1;i++)
               {
                   // if((st1[i]<'A'||st1[i]>'Z')&&(st1[i]<'a'||st1[i]>'z')&&(st1[i]<'0' || st2[i]>'9'))
                   if((!isalpha(st1[i])&&(!isdigit(st1[i]))))
                    {
                         st1[i]=' ';
                    }
               }
                for(int i=0;i<len2;i++)
               {
                  //  if((st2[i]<'A'||st2[i]>'Z')&&(st2[i]<'a'||st2[i]>'z')&&(st2[i]<'0' || st2[i]>'9'))
                                     if((!isalpha(st2[i])&&(!isdigit(st2[i]))))
                    {
                         st2[i]=' ';
                    }
               }
           //cout<<st1<<"\n"<<st2<<endl;
               stringstream ss(st1);
            vt1.clear();
               while(ss>>s)
               {
                    vt1.push_back(s);
                    //int j=i-1;
               //cout<<s<<endl;
               }
               wrd1=vt1.size();
                              stringstream s2 (st2);
                              vt2.clear();
               while(s2>>s)
               {
                    vt2.push_back(s);
                                      //cout<<s<<endl;
               }
               wrd2=vt2.size();
               if(wrd1==0||wrd2==0)
               {
             printf("%2d. Blank!\n",++cas);
               }
               else{
              // cout<<wrd2<<endl;
        int res=LCS(0,0);
            printf("%2d. Length of longest match: %d\n",++cas,res);
               }
        }
    }
}
