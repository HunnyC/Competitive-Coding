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
int mem[1001][1001];
string s;
int byrec(int l,int r)
{
    if(l>r)return 1;
    if(mem[l][r]!=-1)return mem[l][r];
    return mem[l][r]=(s[l]==s[r])&&byrec(l+1,r-1);

}
void solve()
{
          cin>>s;
          //by rec;
          int n=s.size();
          int ans=0;
          for(int i=0;i<n;i++)
          for(int j=i;j<n;j++)
          {
                ans+=byrec(i,j);
          }
          //by iterative dp
          int dp[1001][1001];
          for(int len=1;len<n;len++)
          {
            for(int l=0;l<n;l++)
            {
                int r=len+l-1;
                if(r>=n)break;
                if(len==1)
                dp[l][r]=true;
                else if(len==2)
                dp[l][r]=s[l]==s[r];
                else
                dp[l][r]=(s[l]==s[r])&&dp[l+1][r-1];

                ans+=dp[l][r];
            }
          }
          cout<<ans;
          vector<int> dp2(n,-1);
          for(int i=0;i<n;i++)
          {
            dp2[i]=1e9;
            for(int j=i;j>=0;j--)
            {if(dp[j][i])
            {
                if(j==0)dp2[i]=-1;
                else dp2[i]=min(dp2[i],1+dp2[j]);

            }}
          }

          cout<<dp[n-1]-1<<endl;
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