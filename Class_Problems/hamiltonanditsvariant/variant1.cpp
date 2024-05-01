
// shortest hamiltonian walk

#include<bits/stdc++.h>
using namespace std;
using ll=long long int; 
ll dp[51][1200];
int n,m;
vector<int>graph[100];
// n -> numbers of node
ll rec(int node,int mask)
{    
      
    
      ll ans=1e18;
      if(mask==(1<<n)-1)
     {
        return 0;
      }

      if(dp[node][mask]!=-1)return dp[node][mask];
      for(auto it:graph[node])
      {
           if(mask&(1<<(it-1))==0)
           {
              ans=min(ans,rec(it,mask|(1<<(it-1))));  //add weight to edge
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