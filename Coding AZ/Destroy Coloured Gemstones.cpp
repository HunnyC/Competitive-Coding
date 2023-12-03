//Destroy Coloured Gemstones
//You are given an array of colored gemstones. In one second, you can remove exactly one continuous substring of colored gemstones that is a palindrome. You have to find the minimum number of seconds needed to destroy all the gemstones.


#include<bits/stdc++.h>
using namespace std;



int n;
int dp[1011][1011];
int a[1011];
int rec(int l,int r)
{
    if(l>r)return 0;
    if(l==r)return 1;
    if(dp[l][r]!=-1)return dp[l][r];
    int ans=1e9;
    ans=1+rec(l+1,r);
    if(a[l]==a[l+1])ans=min(ans,1+rec(l+2,r));
    for(int i=l+2;i<=r;i++)
    {
        if(a[l]==a[i])
            ans=min(ans,+rec(l+1,i-1)+rec(i+1,r));
    }
    return dp[l][r]=ans;
}

void solve()
{
   cin>>n;
   for(int i=0;i<n;i++)
   {
       cin>>a[i];
   }
   memset(dp,-1,sizeof(dp));
   cout<<rec(0,n-1)<<endl;
   

  
 

}
int main()
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