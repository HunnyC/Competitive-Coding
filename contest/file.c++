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
int n;
bool check(int a[],int m)
{
    vector<int>v;
    v.push_back(m);
    for(int i=0;i<n-1;i++)
    {
        v.push_back(v.back()^a[i]);

    }
    for(int i=0;i<v.size()-1;i++)
    {
        if((v[i]^v[i+1])!=a[i]){
            //cout<<v[i]<<" "<<v[i+1]<<" "<<a[i];
            return 0;
        }
        if(v[i]>n-1)return 0;
    }

    for(auto it:v)
    {
        cout<<it<<" ";
    }
    return 1;
}
void solve()
{
    
  cin>>n;
  int a[n];
  for(int i=0;i<n-1;i++)
  {
    cin>>a[i];
  }
  int hi=n-1;
  int lo=0;
  int ans=-1;
  for(int m=0;m<=n-1;m++)
  {
    if(check(a,m))return;
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
        
    }
}