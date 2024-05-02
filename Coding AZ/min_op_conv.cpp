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
void solve()
{
   
   ll x,y;
   cin>>x>>y;
   if(x>=y)
   {
    cout<<x-y;
    return;
   }
   ll ans=0;
   while(y!=x)
   {
    if(x>y)
    {   
           ans+=(x-y);
        y+=(x-y);
     
        break;
    }
    else
    if(y%2==0)
    {
        y/=2;


    }
    else 
    {
        y++;
      
    }
   
    ans++;
    if(y==x)break;
   }
   cout<<ans;
   
    
    
    
    
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