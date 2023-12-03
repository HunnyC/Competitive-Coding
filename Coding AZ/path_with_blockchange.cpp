

#include<bits/stdc++.h>
using namespace std;
#define int long long 
int mod=1e9+7;
int dp[210][210][410];
int a[210][210];
int n,m,k;
int rec(int r,int c,int K)
{
   if(r<0||c<0||K<0)return 0;
    if(r==0&&c==0)
    {
       if(a[r][c]==0) return 1;
        if(K>0)return 1;
        return 0;
    }
    if(dp[r][c][K]!=-1)return dp[r][c][K];
    int ans=0;
    if(r-1>=0)
    {
        if(a[r][c]!=1)
        {
            ans+=rec(r-1,c,K);
       
        }
        else if(K-1>=0)
        {
            ans+=rec(r-1,c,K-1);
           
        }
    }
    
    if(c-1>=0)
    {
         if(a[r][c]!=1)
        {
            ans+=rec(r,c-1,K);
             
        }
        else if(K-1>=0)
        {
            ans+=rec(r,c-1,K-1);
            
        }
    }
    return dp[r][c][K]=ans%mod;
}




void solve()
{  
  
  cin>>n>>m>>k;
  
  for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int l = 0; l <= k; l++)
            {
                dp[i][j][l] = -1;
            }
        }
    }
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<m;j++)
      {
          cin>>a[i][j];
      }
  }
  cout<<rec(n-1,m-1,k)<<endl;
 

  
 

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