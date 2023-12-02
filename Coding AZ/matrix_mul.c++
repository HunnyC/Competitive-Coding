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
int dp[1011][1011];
int done[101][101];
int n,m;
int a[101];
int b[101];
int back[101][101];
int rec(int i,int j)
{
    //pruning
    if(i>j)return 0;
    if(i==j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];

    int ans=1e9;
    for(int k=i;k<j;k++)
    {   
        int t=rec(i,k)+rec(k+1,j)+a[i]*b[j]*b[k];
        ans=min(ans,t);
        if(ans==t)
        {
            back[i][j]=k;
        }
    }
}
int o[101];
int c[1001];
void generate(int i,int j)
{
    if(i==j)return;
    o[i]++;
    c[j]++;
    int mid=back[i][j];
    generate(i,mid);
    generate(mid+1,j);

}
void solve()
{
   cin>>n;
   for(int i=0;i<n;i++)
   {
    cin>>a[i]>>b[i];
   }
   
   memset(dp,-1,sizeof(dp));
   cout<<rec(0,n);
  
   
   
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