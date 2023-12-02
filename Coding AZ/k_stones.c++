#include<bits/stdc++.h>
#define endl '\n'
const int mod = (1e9+7);
using ll = long long int;
using namespace std;
int n,k;
int dp[100100];
int a[101];

int rec(int i)
{
   if(i==0)return 0;
   if(dp[i]!=-1)return dp[i];
   int ans=0;
   for(int j=0;j<n;j++)
   {
    if(a[j]<=i&&rec(i-a[j])==0)
    {
      ans=1;
      break;
    }

   }
   return dp[i]=ans;
}

void solve()
{

  cin>>n>>k;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  for(int i=0;i<=k;i++)
  {
    dp[i]=-1;
  }
  if(rec(k))
  {
    cout<<"First";
  }
  else 
  cout<<"Second";

  
   
   
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