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
int dp[1001][1001];
int p[100];
int n,k;
int rec(int i,int K)
{
    if(i<0)
    {
        if(K==0)return 0;
        return-2e9;

    }
    if(dp[i][K]!=-1)return dp[i][K];
    int ans=rec(i-1,K);
    for(int j=1;j<=i+1;j++)
    {
        ans=max(ans,rec(i-j,K-1)+p[i+1]-p[i-j+1]);
    }
    return dp[i][K]=ans;
}
void solve()
{
    
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
    {
            cin>>a[i];
    }
    p[0]=0;
    for(int i=1;i<=n;i++){
          p[i]=p[i-1]+a[i-1];
    }
    cout<<rec(n-1,k);
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