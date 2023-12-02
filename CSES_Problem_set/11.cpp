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
ll powi(ll a,ll b,ll p)
{
    if(b==0)
    return 1;
    if(b%2)
    {
       ll ans=(a*powi(a,b-1,p))%mod;
       return ans;
    }
    else
    {
          ll ans=powi(a,b/2,p);
          return (ans*ans)%mod;
    }
}
void solve()
{
    int n;
    cin>>n;
    int a=5;
    int cnt=0;
    while(n/a!=0)
    {
      cnt+=n/a;
      a*=5;
    }
    cout<<cnt;

    
    
    
    
    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
        cout<<endl;
    }
}