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
int n,m;
ll rec(vector<vector<int>>&a,vector<vector<int>>&done,vector<vector<ll>>&dp,int i,int j)
{
   // pruning
   if(i<0||j<0)return -1e9;


   //base case;
   if(i==0&&j==0)
   return a[i][j];

   //cache dp
   if(done[i][j]!=-1)
   return dp[i][j];

   ll ans;
   ans = max(a[i][j]+rec(a,done,dp,i-1,j),a[i][j]+rec(a,done,dp,i,j-1));
   done[i][j]=1;
   return dp[i][j]=ans;

}

void solve()
{  
     cin>>n>>m;
     vector<vector<int>>a(n,vector<int>(m,0)),done(n,vector<int>(m,-1));
     vector<vector<ll>>dp(n,vector<ll>(m,0));

 
   for(int i=0;i<n;i++)
   {
    for(int j=0;j<m;j++)
    {
          cin>>a[i][j];
    }
   }
   cout<<rec(a,done,dp,n-1,m-1);
   
   
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