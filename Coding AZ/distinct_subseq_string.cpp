#include<bits/stdc++.h>
#define endl '\n'
const int mod = 998244353;
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
    string s;
    cin>>s;
    int n=s.size();
    vector<int>dp(n+2),sum(n+2);
    dp[0]=1;
    sum[0]=1;
   string st=" ";
   st+=s;
   s=st;
    vector<int>last(100,-1);
     
    for(int i=1;i<s.size();i++)
    {
        dp[i]=sum[i-1];
        if(last[s[i]]>-1)
        {
            dp[i]-=sum[last[s[i]]-1];
        }
        last[s[i]]=i;
        
        sum[i]+=sum[i-1]+dp[i];
        sum[i]%=mod;
    }
   // cout<<s<<endl;
    cout<<sum[n]<<endl;
    
    
    
    
    
    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
   // cin>>t;
    string s;
    //cin>>s;
    while(t--)
    {
        solve();
        //cout<<endl;
    }
}