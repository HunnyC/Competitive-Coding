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
// ll rec(int board,int mask)
// {   
    
//     if(board==n+1)
//     {
//         return 0;
        
//     }
//     if(dp[board][mask]!=-1)return dp[board][mask];
//     ll ans=0;
//     for(int i=0;i<2*n;i++)
//     {
//         for(int j=0;j<2*n;j++)
//         {
//             if((mask&((1<<i)|(1<<j)))==0)
//             {
//               ans=max(ans,rec(board+1,mask|(1<<i)|(1<<j))+board*abs(A[i]-A[j])*__gcd(A[i],A[j]));
            
//             }
//         }
//     }
//     return dp[board][mask]=ans;

// }
// state space reduction:
ll dp1[(1<<21)];
ll gcd[22][22];
ll rec(int board,int mask,vector<ll>&A)
{   
    board=__builtin_popcount(mask)/2+1;
    if(board==n+1)
    {
        return 0;
        
    }
    if(dp1[mask]!=-1)return dp1[mask];
    ll ans=0;
    for(int i=0;i<2*n;i++)
    {
        for(int j=0;j<2*n;j++)
        {
            if((mask&((1<<i)|(1<<j)))==0)
            {
               ans=max(ans,rec(board+1,mask|(1<<i)|(1<<j),A)+1LL*board*1LL*abs(A[i]-A[j])*gcd[i][j]);
            
            }
        }
    }
    return dp1[mask]=ans;

}

// 

void solve()
{
    cin>>n;
  
    vector<ll>A(2*n+1);
    for(int i=0;i<2*n;i++)
    {
        cin>>A[i];
    }
    //memset(dp1,-1,sizeof(dp1));
    for(int i=0;i<(1<<(2*n+1));i++)
    {
        dp1[i]=-1;
    }
    for(int i=0;i<2*n;i++)
    {
        for(int j=0;j<2*n;j++)
        {
            gcd[i][j]=__gcd(A[i],A[j]);
        }
    }
   
    cout<<rec(0,0,A);
    

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