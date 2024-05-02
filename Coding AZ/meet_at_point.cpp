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
  int n;
  cin>>n;
  int a[n],b[n];
  for(int i=0;i<n;i++)cin>>a[i]>>b[i];
   sort(a,a+n);
   sort(b,b+n);
  int x=a[(n)/2];
  int y=b[(n)/2];
  ll ans=0;
  for(int i=0;i<n;i++)
  {
    ans+=abs(x-a[i])+abs(y-b[i]);
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