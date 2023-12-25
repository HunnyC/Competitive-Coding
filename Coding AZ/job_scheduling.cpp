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
struct job{
    int start,end,pay;
};
void solve()
{   
    int n;
    cin>>n;
    vector<job>jb(n);
    for(int i=0;i<n;i++)
   {
       cin>>jb[i].start>>jb[i].end>>jb[i].pay;
   }
    sort(jb.begin(),jb.end(),[](job A,job B){
        return A.start<B.start;
    });
    for(int i=0;i<n;i++)
    {
        cout<<jb[i].start<<" "<<jb[i].end<<" "<<jb[i].pay;
        cout<<endl;
    }
    vector<int>dp(n+1);
    int ans=0;
    vector<int>suffixmax(n+1);

    //n^2
    // for(int i=n-1;i>=0;i--)
    // {
    //     dp[i]=jb[i].pay;
    //     for(int j=i+1;j<n;j++)
    //     {
    //         if(jb[i].end<jb[j].start)
    //         {
    //             dp[i]=max(dp[i],dp[j]+jb[i].pay);
    //         }
    //     }
    //     ans=max(ans,dp[i]);
    // }
    
    //nlogn
    for(int i=n-1;i>=0;i--)
    {
        dp[i]=jb[i].pay;
        int low=i+1;
        int hi=n-1;
        int a=-1;
        while(hi>=low)
        {
            int mid=(low+hi)/2;
            if(jb[i].end<jb[mid].start)
            {
                hi=mid-1;
                a=mid;
            }
            else
            {
                low=mid+1;
            }
        }
        if(a!=-1)
        {
            dp[i]=max(dp[i],suffixmax[a]+jb[i].pay);
        }
        ans=max(ans,dp[i]);
        if(i+1<n)
        {
          suffixmax[i]=max(suffixmax[i+1],dp[i]);
        }
    }
    cout<<ans<<endl;
    
    
    
    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
        cout<<endl;
    }
}