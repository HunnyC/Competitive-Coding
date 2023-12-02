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
int dp[1011];
int n;
int a[100];
int rec(int level)
{
   // pruning
   if(level<0)return 0;


   //base case;

   //cache dp
   if(dp[level]!=-1)
   return dp[level];
   //computation
   int ans = 1;
   for(int j=0;j<level;j++)
   {
    if(a[j]<a[level])
    {
        ans = max(ans,1+rec(j));
    }
   }
   
   return dp[level]=ans;

   
   

   
}

void solve()
{
   cin>>n;
   memset(dp,-1,sizeof(dp));
   for(int i=0;i<n;i++)
   {
    cin>>a[i];
   }
 
  int best=0;
  for(int i=0;i<n;i++)
  {
    best=max(best, rec(i));
  }
   cout<<"best"<<" "<<best;
   
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