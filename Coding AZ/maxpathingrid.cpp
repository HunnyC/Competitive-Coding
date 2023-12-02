#include<bits/stdc++.h>
using namespace std;
int row,column;
vector<vector<int>>grid;
int dp[1000][1000];
int check[1000][1000];
int rec(int r,int c)
{
    if(r<0||c<0)return -1e9;
    if(r>row||c>column) return -1e9;
    if(r==0&&c==0)return grid[0][0];
    if(check[r][c]!=-1)
    return dp[r][c];

    check[r][c]=1;
    int ans=-1e9;
    ans=max(ans,grid[r][c]+rec(r-1,c));
    ans=max(ans,grid[r][c]+rec(r,c-1));
    return dp[r][c]=ans;

}
void solve()
{

 cin>>row>>column;
 grid.resize(row,vector<int>(column));
 for(int i=0;i<row;i++)
 {
    for(int j=0;j<column;j++)
    {
        cin>>grid[i][j];
    }
 }
 memset(dp,-1,sizeof(dp));
 memset(check,-1,sizeof(check));
 cout<<rec(row-1,column-1);
 
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    t=1;
    while(t--)
    {
        solve();

    }
}