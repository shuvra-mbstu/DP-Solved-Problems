#include<bits/stdc++.h>
#define mx 100007
#define pb push_back
using namespace std;
vector<int>vt[30];
int dir[50],dp[50],num,start;

int longest(int u)
{
   // cout<<"@"<<u<<endl;
    if(dp[u]!=-1) return dp[u];
    //cout << num << endl;
    int maxi=0,coun=0;

    for(int v=0; v<num; v++)
    {
        //cout << "ok\n";

        coun=0;
        for(int i=0; i < vt[v].size(); i++)
        {
            if(vt[v][i]<=vt[u][i])
            {
               // cout<<vt[v][i]<<endl;
                coun=1;
                break;
            }
        }

        if(coun==0)
        {
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
        printf("%d ",start+1);
        start=dir[start];
    }
    printf("%d\n",start + 1);
}

int main()
{
    int node,val;
    while(scanf("%d %d",&num,&node)!=EOF)
    {
        memset(dp,-1,sizeof(dp));
        memset(dir,-1,sizeof(dir));

        for(int i = 0; i<num; i++)
        {
            for(int j=0; j<node; j++)
            {
                scanf("%d",&val);
                vt[i].pb(val);
            }

            sort(vt[i].begin(),vt[i].end());
        }

        val = 0;
        //cout << num << endl;
        for(int i = 0; i < num; i++){
        if(longest(i) > val){
            start = i;
            val = longest(i);
        }
        }
        printf("%d\n",val);
    solution(start);
        for(int i = 0; i <= num; i++)
            vt[i].clear();
}
}
