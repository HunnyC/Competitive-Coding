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
int dp[1010][1011];
int n,m;
string a,b;
int rec(int i,int j)
{
    //pruning
   

    //base
    if(i>=n||j>=m)return 0;

    //cache
    if(dp[i][j]!=-1)
    return dp[i][j];

    //computation
    int ans=0;
       ans=max(ans,rec(i+1,j));
    ans=max(ans,rec(i,j+1));
    if(a[i]==b[j])
    {
           ans=max(ans,1+rec(i+1,j+1));
    }
  
   
    return dp[i][j]=ans;

}

void solve()
{
   
   cin>>a>>b;
    n=(int)a.size();
    m=(int)b.size();
   memset(dp,-1,sizeof(dp));
   cout<<rec(0,0);
  cout<<dp[1][0];
   
   
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