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
int n,m;
int cal(int level);

int dp[1001][1001];
int dp1[1001];
int cost[1001][1001];
int d;
int rec(int level,int i)
{
    if(level==n)
    return 0;

    if(dp[level][i]!=-1)return dp[level][i];

    int ans=0;
    ans=min( cal(level+1)   ,rec(level,i)+cost[level][i]-((i==0)?0:d));

    return dp[level][i]=ans;

}
int cal(int level){

    int ans=0;
    if(dp1[level]!=0)return dp1[level];
    for(int i=0;i<m;i++)
    {
        ans=min(ans,rec(level,i)+cost[level-1][i]);
    }
    return dp1[level]=ans;
}

void solve()
{
    cin>>n>>m>>d;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>cost[i][j];
        }
    }
  int ans=0;
  for(int i=0;i<m;i++)
  {
    ans=min(0,i);
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