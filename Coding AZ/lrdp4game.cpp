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
int a[100];

int rec(int i,int j)
{
   if(i==j)return a[i];

   if(done[i][j]!=-1)
   return dp[i][j];
   done[i][j]=1;
   int ans=max(a[i]-rec(i+1,j),a[j]-rec(i,j-1));
   return dp[i][j]=ans;
}

void solve()
{
   cin>>n;
   for(int i=0;i<n;i++)
   {
    cin>>a[i];
   }
   for(int i=0;i<n;i++)
   for(int j=0;j<n;j++)
   done[i][j]=-1;
  
  cout<<rec(0,n-1);

  
   
   
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