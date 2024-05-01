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
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        
    }
    vector<int>lis;
    for(int i=0;i<n;i++)
    {
        if(lis.empty()||lis.back()<=a[i])
        {  
            if(lis.empty())
            lis.push_back(a[i]);
            else
            if(lis.back()!=a[i]);
            lis.push_back(a[i]);
            
        }
        else
        {
            auto it=lower_bound(lis.begin(),lis.end(),a[i]);
            *it=a[i];
        }
        
    }
    cout<<lis.size();
    
    
    
    
    
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