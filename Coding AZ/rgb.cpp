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
    
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int>pref(n+1,0);
        int ans=1e9;
    for(int i=0;i<n;i++)
    {   
        if(i%3==0)
        {
           if(s[i]!='R')
           {
               pref[i+1]=pref[i]+1;
           }
           else pref[i+1]=pref[i];
           
        }else if(i%3==1)
        {
              if(s[i]!='G')
              {
                pref[i+1]=pref[i]+1;
                
              }else pref[i+1]=pref[i];
        }
        else 
        {
               if(s[i]!='B')
              {
                pref[i+1]=pref[i]+1;
                
              }else pref[i+1]=pref[i];
        }

    } 

    for(int i=k;i<n+1;i++)
    {
         ans=min(ans,pref[i]-pref[i-k]);
    }
    // 
    pref.clear();
        for(int i=0;i<n;i++)
    {   
        if(i%3==0)
        {
           if(s[i]!='G')
           {
               pref[i+1]=pref[i]+1;
           }
           else pref[i+1]=pref[i];
           
        }else if(i%3==1)
        {
              if(s[i]!='B')
              {
                pref[i+1]=pref[i]+1;
                
              }else pref[i+1]=pref[i];
        }
        else 
        {
               if(s[i]!='R')
              {
                pref[i+1]=pref[i]+1;
                
              }else pref[i+1]=pref[i];
        }

    } 

    for(int i=k;i<n+1;i++)
    {
         ans=min(ans,pref[i]-pref[i-k]);
    }
    
    pref.clear();
        for(int i=0;i<n;i++)
    {   
        if(i%3==0)
        {
           if(s[i]!='B')
           {
               pref[i+1]=pref[i]+1;
           }
           else pref[i+1]=pref[i];
           
        }else if(i%3==1)
        {
              if(s[i]!='R')
              {
                pref[i+1]=pref[i]+1;
                
              }else pref[i+1]=pref[i];
        }
        else 
        {
               if(s[i]!='G')
              {
                pref[i+1]=pref[i]+1;
                
              }else pref[i+1]=pref[i];
        }

    } 

    for(int i=k;i<n+1;i++)
    {
         ans=min(ans,pref[i]-pref[i-k]);
    }
    cout<<ans<<endl;
    
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