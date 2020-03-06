#include<bits/stdc++.h>
using namespace std;

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
int main()
{
     string s1, s2;
     while(cin >> s1 >> s2)
     {
          if(comp(s1,s2)==1)
          {
               cout << "s1 > s2" << endl;
          }
          else if(comp(s1,s2)==0)
          {
               cout << "s1 < s2" << endl;
          }
          else
               cout<<"S1==S2"<<endl;
     }
}
