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
int dp[101100];
int n;
string a;
unordered_map<char,int>mapi;


void solve()
{

   memset(dp,-1,sizeof(dp));
   cin>>a;
   n=a.size();
  dp[0]=1;
  for(int i=0;i<n;i++)
  {
    mapi[a[i]]=-1;
  }
  for(int i=1;i<=n;i++)
  {
    dp[i]=2*dp[i-1];
    
    if(mapi[a[i-1]]!=-1)
    {
         dp[i]=dp[i]-dp[mapi[a[i-1]]];
    }
    mapi[a[i-1]]=i-1;
  }
  cout<<dp[n];
  
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