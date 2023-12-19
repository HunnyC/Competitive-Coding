#include<bits/stdc++.h>
#define endl '\n'
const int mod = (1e9+7);
using ll = long long int;
using namespace std;
ll binary(ll a,ll b, ll p)
{  ll ans=1;
   if(b==0)return 1;
if(a==1)return 1;
   while(b)
   {
       if(b%2==1)
       {
         ans = ((ans % p) * (a % p)) % p;
       }
       a = ((a % p) * (a % p)) % p;
       b/=2;
   }
 return  ans;
}
int dp[1001][1001];
int n,m;
int rec(int i,int j)
{
    if(i==0&&j==0)
    {
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=0;
    for(int z=0;z<i;z++)
    {
        if(rec(z,j)==0)
        {
            ans=1;
            break;
        }
    }
        for(int z=0;z<j;z++)
    {
        if(rec(i,z)==0)
        {
            ans=1;
            break;
        }
    }
        for(int z=1;z<=min(i,j);z++)
    {
        if(rec(i-z,j-z)==0)
        {
            ans=1;
            break;
        }
    }
    return dp[i][j]=ans;
}
void solve()
{
    
 memset(dp,-1,sizeof(dp));
cin>>n>>m;
cout<<rec(n,m);
memset(dp,-1,sizeof(dp));
for(int x=0;x<n;x++)
{
    for(int y=0;y<m;y++)
    {
        if(x==0&y==0)
        dp[x][y]=0;
        int ans=0;
      for(int z=0;z<x;z++)
    {
        if(dp[z][y]==0)
        {
            ans=1;
            break;
        }
    }
        for(int z=0;z<y;z++)
    {
        if(dp[x][z]==0)
        {
            ans=1;
            break;
        }
    }
        for(int z=1;z<=min(x,y);z++)
    {
        if(rec(x-z,y-z)==0)
        {
            ans=1;
            break;
        }
    }
        dp[x][y]=ans;
    }
}


    
    
    
    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--)
    {
        solve();
        cout<<endl;
    }
}