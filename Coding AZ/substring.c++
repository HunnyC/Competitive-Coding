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
int dp[1010];
int n,m;
string a,b;
int nm,nmm;
string s1,s2;
int rec(int i)
{
    //pruning
   

    //base
    if(i>=nm)return 0;

    //cache
    if(dp[i]!=-1)
    return dp[i];

    //computation
    int ans=0,ans1=0;
    for(int j=i;j<nmm;j++)
    {
        if(s1[i]==s2[j])
        {
            ans=max(ans,1+rec(i+1));
        }
        else ans=0;
        ans1=max(ans,ans1);
    }
    return dp[i]=ans;

}

void solve()
{
   
   cin>>a>>b;
    n=(int)a.length();
    m=(int)b.length();
    nm=min(n,m);
    if(nm==n){s1=a;s2=b;nmm=m;}
    else {s1=b,s2=a;nmm=n;}
   memset(dp,-1,sizeof(dp));
   cout<<rec(0)<<endl;
  
   
   
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
       
   }
}