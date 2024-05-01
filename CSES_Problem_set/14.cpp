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
vector<pair<int,int>>v;
int tower(int n,int a,int b,int c)
{
        
        if(n==1)
        {
           
            v.push_back({a,c});
            return  1;
        }
      
       
        int cnt=1;
       cnt+=tower(n-1,a,c,b);
        v.push_back({a,c});
       cnt+=tower(n-1,b,a,c);
      
       return cnt;

       

}
void solve()
{
    int n;
    cin>>n;
   cout<<tower(n,1,2,3)<<endl;
   for(auto it:v)
   {
    cout<<it.first<<" "<<it.second<<endl;
   }











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