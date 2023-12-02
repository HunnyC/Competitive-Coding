#include<bits/stdc++.h>
using namespace std;



int n,t;
vector<int>a;
vector<vector<int>>dp;

int rec(int label,int t)
{
    if(t<0)return 0;
    if(label>=n)return 0;
    if(label==n-1)
    {
        if(t==0)return 1;
        return 0;
    }
    if(dp[label][t]!=-1)
    {
        return dp[label][t];
    }
    dp[label][t]=rec(label+1,t)||rec(label+1,t-a[label]);
    return dp[label][t];
}
void print(int level,int t)
{
    if(level==n)return;
    if(rec(level+1,t))
    {
        print(level+1,t);
    }
    else
    {    
        cout<<a[level]<<" ";
        print(level+1,t-a[level]);

    }
}
void solve()
{

  cin>>n>>t;
  a.resize(n);
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  dp.resize(n+1,vector<int>(t+1,-1));
  if(rec(0,t))
  cout<<"YES";
  else cout<<"NO";
  print(0,t);

}
int main()
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