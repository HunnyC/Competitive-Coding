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

       

vector<int>v;
int n;
ll rec(int i,ll sum1,ll sum2)
{
    if(i==n)
    {
        return abs(sum1-sum2);
    }
    ll ans=0;
    ans=min(rec(i+1,sum1+v[i],sum2),rec(i+1,sum1,sum2+v[i]));
    return ans;
}
void solve()
{
    
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        v.push_back(t);
    }
   cout<<rec(0,0,0);











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