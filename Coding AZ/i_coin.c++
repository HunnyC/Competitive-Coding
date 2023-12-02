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
vector<vector<long double>>dp;
int n;
long double a[3001];


long double rec(int level,int head)
{  
    if(level==n)
    {
        if(head>n/2)return 1;
        return 0;
    }
   if(dp[level][head]!=-1)
   {
      return dp[level][head];
   }
   long double ans=0;
   ans+=a[level]*rec(level+1,head+1);
   ans+=(1-a[level])*rec(level+1,head);
   return dp[level][head]=ans;

}

void solve()
{
   cin>>n;
   for(int i=0;i<n;i++)
   {
    cin>>a[i];
   }
   dp.resize(n+1,vector<long double>(n+1,-1));
   cout<<setprecision(15);
   cout<<rec(0,0);
  
   
   
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