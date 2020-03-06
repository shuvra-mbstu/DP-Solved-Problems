#include<bits/stdc++.h>
using namespace std;
vector<string> vt;
int comp(string s1,string s2)
{
     int len1=s1.size();
     int len2=s2.size();

     if(len1>len2)return 1;
     else if(len2>len1) return 0;
     for(int i=0;i<len1;i++)
     {
          if(s1[i]>s2[i]) return 1;
          else if(s2[i]>s1[i]) return 0;
     }
     return 2;
}
string sum(string s1, string s2)
{
    string ss;
    int len1=s1.size();
    int len2=s2.size();
    if(len1>len2)
    {
        while(s1.size()>s2.size())
        {
            s2.insert(s2.begin(),'0');
        }
    }
    else  if(len2>len1)
    {
        while(s2.size()>s1.size())
        {
            s1.insert(s1.begin(),'0');
        }
    }
    // cout<<s1<<endl<<s2<<endl;
    len1=s1.size();
    int mod=0;
    for(int i=len1-1; i>=0; i--)
    {
        int a=(s1[i]-'0')+(s2[i]-'0')+mod;
        //int mod=a%10;
        mod=a/10;
        a=a%10;
        ss+=(a+'0');
    }
    if(mod!=0)
    {
        ss+=mod+'0';
    }
    // cout<<ss<<endl;
    reverse(ss.begin(),ss.end());
    while(ss[0]=='0')
    {
        ss.erase(ss.begin());
    }
    return ss;
}
void fun()
{
    int i=2;
    vt.push_back("1");
    vt.push_back("1");
    while(i!=507)
    {
        string SS =sum(vt[i-1],vt[i-2]);
//        cout << SS << endl;
        vt.push_back(SS);
        i++;
    }
}
int main()
{
    fun();
    string st1,st2;
    while(cin>>st1>>st2)
    {
        if(st1=="0" && st2=="0")break;

        int ind1, ind2;
        for(int i=1; i<=500; i++)
        {

            if((comp(vt[i],st1)==1)||(comp(vt[i],st1)==2))
            {
                ind1 = i;
                break;
            }
        }
        //cout<<ind1<<endl;
         for(int i=1; i<=500; i++)
        {

            if((comp(vt[i],st2)==1))
            {
                ind2 = i;
                break;
            }
            else if((comp(vt[i],st2)==2))
            {
                 ind2=i+1;
            }
        }
                //cout<<ind2<<endl;

        cout << ind2-ind1 << endl;
    }
}
