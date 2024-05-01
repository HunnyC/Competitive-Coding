#include<bits/stdc++.h>
#define endl '\n'
const int mod = (1e9+7);
#define int long long
using namespace std;

int n,m;
int dp[14][14][(1<<13)];

int rec(int i,int j,int mask)
{
    
    //base case 
    // Check array bounds
    if(i==n)
    {   
        if(mask==(1<<(m))-1)
        return 1;
        
        return 0;

    }
     int ans=0;

    if(j==m)
    {
        return rec(i+1,0,mask);
    }
    if(dp[i][j][mask]!=-1)return dp[i][j][mask];
    
     if((mask&1)==0)
     {  
        
         ans=rec(i,j+1,(mask>>1)|(1<<(m-1)));
 

     }
     else
     {  
       
         ans=rec(i,j+1,mask>>1);
        
        if((mask&(1<<(m-1)))==0&&j!=0)
        {
        ans+=rec(i,j+1,(mask>>1)|(1<<(m-1))|(1<<(m-2)));
       
        }

    
     
     }

      
      



    return dp[i][j][mask]=ans;
   
}
void solve()
{
    cin>>n>>m;
     memset(dp,-1,sizeof(dp));
    cout<<rec(0,0,(1<<m)-1);
    
    
    
    
    
}
signed main()
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