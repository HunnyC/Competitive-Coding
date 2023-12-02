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
int dp[1011][1011];
int done[101][101];
int n,m;
int a[100];
int rec(int i,int j)
{
    //pruning
   

    //base
    if(i+1==j)return 0;

    //cache
    if(dp[i][j]!=-1)
    return dp[i][j];

    //computation
     int ans=1e9;
     for(int l=i+1;l<=j-1;l++)
     {
        ans=min(ans,rec(i,l)+rec(l,j)+a[j]-a[i]);
     }
    return dp[i][j]=ans;

}

void solve()
{
   cin>>n;
   for(int i=0;i<n;i++)
   {
    cin>>a[i];
   }
   
   memset(dp,-1,sizeof(dp));
   cout<<rec(0,n);
  
   
   
}
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);cout.tie(0);
   int t=1;
   // cin>>t;
   while(t--)
   {
       solve();
       cout<<endl;
   }
}