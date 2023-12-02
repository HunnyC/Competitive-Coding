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
int done[101][101];
int n,m;
string a,b;
int rec(int i)
{
    //pruning

    //base
    if(i==0)
    return 0;

    

    //cache
    if(dp[i]!=-1)
    return dp[i];

    //computation
    int ans=0;
    for(int m=0;(1<<m)<=i;m++)
    {
        if(rec(i-(1<<m))==0)
        {
            ans=1;
            break;
        }
    }
    return dp[i]=ans;

}

void solve()
{

  
   memset(dp,-1,sizeof(dp));
   for(int i=0;i<20;i++)
   {
            cout<<rec(i)<<endl;

   }
  
   
   
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