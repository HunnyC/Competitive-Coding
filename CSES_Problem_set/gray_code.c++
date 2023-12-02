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
   if(n==1)
   {
    cout<<0<<endl;
    cout<<1<<endl;
    return;
   }
     int m=pow(2,n);
   vector<vector<bool>>v(m,vector<bool>(n,0));
   for(int i=0;i<n;i++)
   {  
    int c=0;
      for(int j=(pow(2,i));j<m;j++)
      {
            if(c==(pow(2,i+1)))
            {   
                
                for(int i=0;i<c-1;i++)
                {
                    
                    j++;
                }c=0;

            }
            else
            {
                c++;
                v[j][i]=1;
            }
      }
   }

  for(int i=0;i<m;i++)
  {
    for(int j=n-1;j>=0;j--)
    {
        cout<<v[i][j];
    }
    cout<<endl;
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