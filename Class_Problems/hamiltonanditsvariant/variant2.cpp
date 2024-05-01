//Number of hamiltonian walks



#include<bits/stdc++.h>
using namespace std;
using ll=long long int; 
ll dp[51][1200];
int n,m;
vector<int>graph[100];
// n -> numbers of node
ll rec(int node,int mask)
{    
      
    
      ll ans=0;
      if(mask==(1<<n)-1)
      {
        
        return 1;                // for every reaching return 1;
        
      }
      if(dp[node][mask]!=-1)return dp[node][mask];
      for(auto it:graph[node])
      {
           if(mask&(1<<(it-1))==0)
           {
              ans+=rec(node+1,mask|(1<<(it-1)));// make imaginary  zero to all 
           }

      }

      return dp[node][mask]=ans;
}
void solve()
{
    
    //required code inputs

     memset(dp,-1,sizeof(dp));


    cout<<rec(0,0)<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    t=1;
    cin>>t;
    while(t--)
    {
        solve();

    }
}