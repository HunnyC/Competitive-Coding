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
int edges[16][16];
int dp[16][(1<<16)];
int n;
int rec(int pos,int mask)
{   

    if(pos==n+1)return 0;
    if(dp[pos][mask]!=-1)return dp[pos][mask];
    int ans=1e9;
    for(int i=0;i<n;i++)
    {
        if((mask&(1<<i))==0)
        {
             int temp=0;
             for(int j=0;j<n;j++)
             
             {  
                if((mask&(1<<j)))
                temp+=edges[i][j];
             }
             ans=min(ans,rec(pos+1,mask|(1<<i))+temp);
        }
    }





    return dp[pos][mask]=ans;
}
void solve()
{
   cin>>n;
   for(int i=0;i<n;i++)
   {
    for(int j=0;j<n;j++)
     {
        cin>>edges[i][j];
     }
   }
   cout<<rec(1,0);

    
    
    
    
    
    
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