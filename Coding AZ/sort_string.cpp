//Sort the strings

#include<bits/stdc++.h>
using namespace std;
#define int long long 
int dp[110000][4];
vector<int>a;
vector<string>s,rs;
int n;
int rec(int level,int rns)
{
    if(level==n)
    return 0;
    if(dp[level][rns]!=-1)return dp[level][rns];
    int ans=1e18;
   
    if(rns)
    {
        
        if(rs[level-1]<=s[level])
        {
            ans=min(ans,rec(level+1,0));
        }
        if(rs[level-1]<=rs[level])
        {
            ans=min(ans,a[level]+rec(level+1,1));
        }
    }
    else
    {
        if(s[level-1]<=s[level])
        {
            ans=min(ans,rec(level+1,0));
        }
        if(s[level-1]<=rs[level])
        {
            ans=min(ans,a[level]+rec(level+1,1));
        }
    }
    return dp[level][rns]=ans;
}




void solve()
{  
    
    cin>>n;
    a.resize(n);
    s.resize(n);
    rs.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        rs[i]=s[i];
        reverse(rs[i].begin(),rs[i].end());
    }
    memset(dp,-1,sizeof(dp));
    int ans=1e18;
    ans=min(rec(1,1)+a[0],rec(1,0));
    if(ans==1e18)
    {
        cout<<-1<<endl;
        return;
    }
    
    
    cout<<ans<<endl;
    
    rs.clear();
    s.clear();
    a.clear();
 


  
 

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