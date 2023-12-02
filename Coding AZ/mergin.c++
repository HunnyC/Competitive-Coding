#include<bits/stdc++.h>
using namespace std;
int n;
int dp[1001][1001];
int arr[1001];
int rec(int l,int r)
{
    if(l==r)return 0;
    if(dp[l][r]!=-1)
    return dp[l][r];

    int tot=0;
    int sum=0;
    int ans=-1e9;
    for(int i=l;i<r;i++)
    {
        tot+=arr[i];
    }
    for(int i=l;i<r;i++)
    {
        sum+=arr[i];
        ans=max(ans,rec(l,i)+rec(i+1,r)+(((tot-sum)%100)*(sum%100)%100));
    }
return dp[l][r]=ans;
}
void solve()
{

 cin>>n;
 for(int i=0;i<n;i++)
 {
    cin>>arr[i];
 }
 memset(dp,-1,sizeof(dp));
 cout<<rec(0,n);
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