//Sort the strings

#include<bits/stdc++.h>
using namespace std;
using ll=long long int; 
ll dp[51][1200];
int n,m;
int happy[51][51];

ll rec(int level,int mask)
{
      if(level==m)
      {
         return 0;
      }
      if(dp[level][mask]!=-1)return dp[level][mask];
      ll ans=rec(level+1,mask);
      for(int rank=0;rank<n;rank++)
      {    
           if((mask&(1<<rank))==0)
           ans=max(ans,rec(level+1,(mask|(1<<rank)))+happy[level][rank]);
      

           
      }





      return dp[level][mask]=ans;
}
void solve()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>happy[i][j];
        }
    }

    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    t=1;
    cin>>t;
    while(t--)
    {
        solve();

    }
}