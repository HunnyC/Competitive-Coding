
// shortest hamiltonian walk

#include<bits/stdc++.h>
using namespace std;
using ll=long long int; 
ll dp[16][(1<<15)+2];
int n,m;
vector<vector<int>>graph(16,vector<int>(16,0));
// n -> numbers of node
int g;
ll rec(int node,int mask)
{    
      
    
      ll ans=1e18;
      if(mask==(1<<n)-1)
      {
        return graph[g][node];
      }

      if(dp[node][mask]!=-1)return dp[node][mask];
      for(auto it:graph[node])
      {
           if(mask&(1<<(it-1))==0)
           {
              ans=min(ans,rec(it,mask|(1<<(it-1)))+graph[node][it]);  //add weight to edge
           }

      }

      return dp[node][mask]=ans;
}
void solve()
{
    
    //required code inputs
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        graph[0][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
             int t;
             cin>>t;
             graph[i][j]=t;
         

        }
    }
     memset(dp,-1,sizeof(dp));
       
       ll ans=1e18;
         int mask=0;
          for(auto it:graph[0])
      {     
              g=it;
          
              ans=min(ans,rec(it,mask|(1<<(it-1)))+graph[0][it]);  //add weight to edge
           

      }
    cout<<ans<<endl;
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