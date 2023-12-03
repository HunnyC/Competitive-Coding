//Given a grid of size n*m with non-negative integers, you need to find the maximum path sum from (1, 1) to (n, m). You are allowed to move from (x, y) to (x+1, y) and (x, y) to (x, y+1).
#include<bits/stdc++.h>
using namespace std;
int mod=1e9+7;
using ll=long long int;
int n,m;
vector<vector<int>>dp;
vector<vector<int>>grid;


ll rec(int r,int c)
{
    if(r<0||c<0)return -1e9;
    if(r==0&&c==0)return grid[r][c];
    if(dp[r][c]!=-1)return dp[r][c];
    int ans=0;
    
    ans=grid[r][c]+max(rec(r+1,c),rec(r,c+1));
    
    return dp[r][c]=ans;
    
    
    
    
    
}


void solve()
{
    
    cin>>n>>m;
    grid.resize(n,vector<int>(m));
    dp.resize(n,vector<int>(m,-1));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>grid[i][j];
        }
    }

    cout<<rec(n-1,m-1);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}