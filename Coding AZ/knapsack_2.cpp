#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
using ll=long long int;
int n;
int W;

ll dp[1011][101100];
vector<int>w,v;
ll rec(int level,int value)
{
    if(value<0)return 1e9;
   if(level==n)
   {
      //if(value<0)return 1e9;
      if(value==0)
      return 0;
      return 1e9;
   }
   
   if(dp[level][value]!=-1)return dp[level][value];
   
   int ans=1e9;
   
   ans=min(rec(level+1,value),w[level]+rec(level+1,value-v[level]));
   return dp[level][value]=ans;
   
    
    
    
    
    
}


void solve()
{
    cin>>n>>W;
    memset(dp,-1,sizeof(dp));
    v.resize(n+2);
    w.resize(n+2);
     int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>w[i]>>v[i];
        sum+=v[i];
    }
   
    
    int ans;
    for(int i=0;i<=sum;i++)
    {   
        int t=rec(0,i);
        if(t<=W)
        ans=i;
        
    }
    cout<<ans;
    
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}