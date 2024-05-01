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
vector<int>g[10010];
int indp[10010];
int outdp[10010];
int size[10010];
int n;
void indfs(int node,int parent)
{
    size[node]=1;
    indp[node]=0;
    for(auto it:g[node])
    {
        if(it!=parent)
        {
            indfs(it,node);
            size[node]+=size[it];
            indp[node]+=indp[it]+size[it];
        }
    }
    
}

void outdfs(int node,int parent)
{
   if(node==1)
   {
     outdp[node]=0;
   }
   else
   {
    outdp[node]=outdp[parent]+indp[parent]-(indp[node]+size[node])+n-size[node];
   }

   for(auto v:g[node])
   {
      if(v!=parent)
      {
         outdfs(v,node);
      }
   }
}
void solve()
{
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    indfs(1,0);
    outdfs(1,0);
    for(int i=1;i<=n;i++)
    {
        cout<<indp[i]+outdp[i]<<" "<<endl;
    }
    
    
    
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