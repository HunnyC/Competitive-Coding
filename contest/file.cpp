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
    
   int n,k,pb,ps;
   cin>>n>>k>>pb>>ps;
   int p[n],a[n];
   for(int i=0;i<n;i++)cin>>p[i];
   for(int i=0;i<n;i++)cin>>a[i];

   ll s1=a[pb],s2=a[ps];
   int k1=k;
   k--;
   k1--;
   while(1)
   {  
      
      if(a[pb]<a[p[pb]])
      {
        
        s1+=a[p[pb]];
        pb=p[pb];
        k--;
      }
      else break;

   }
   s1+=(k*a[pb]);

      while(1)
   {  
      
      if(a[ps]<a[p[ps]])
      {
        
        s2+=a[p[ps]];
        ps=p[ps];
        k1--;
        
      }
      else break;

   }
   s2+=(k1*a[ps]);
   
   if(s1==s2)
   {
    cout<<"Draw";
   }
   else if(s1>s2)
   {
    cout<<"Bodya";
   }
   else
   { 
    cout<<"Sasha";

   }

   
   
    
    
    
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