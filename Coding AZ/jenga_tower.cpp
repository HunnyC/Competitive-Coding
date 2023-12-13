#include<bits/stdc++.h>
#define endl '\n'
const int mod = (1e9+7);
using ll=long long int;
//#define int long long
using namespace std;

ll dp[1000050][2];
int n;
ll rec(int i,int c)
{  
    //cout<<i<<" ";
    if(i==1)
    {
        return 1;
    }
    
    if(dp[i][c]!=-1)return dp[i][c];
    ll ans=0;
    if(c==0)
    {
        ans=2*rec(i-1,0)+rec(i-1,1);
        
        ans%=mod;
      
     }
    else
    {
        ans=4*rec(i-1,1)+rec(i-1,0);
        
        
        ans%=mod;
    }
       
        ans%=mod;
    return dp[i][c]=ans;
   
}
void solve()
{
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<2;j++)
        {
            dp[i][j]=-1;
        }
    }
    
    //memset(dp,-1,sizeof(dp));
    cout<<(rec(n,0)+rec(n,1))%mod<<endl;
    
    
    
    
    
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
    
    }
}