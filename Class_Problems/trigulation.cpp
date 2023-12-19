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
pair<double,double> p[101];
double sq(int x)
{
    return x*x;
}
double cost(int x,int y)
{
    double dis=sqrt(sq(p[x].first-p[y].first)+sq(p[x].second-p[y].second));
    return sin(dis);
}
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i].first>>p[i].second;
    }
    int dp[n+1][n+1];
    //for recursive don't use dp double default -1 it may not compare for default case -1 precison
    
    for(int len=3;len<=3;len++)
    {
        for(int l=1;l+len-1<=n;l++)
        {
            int r=l+len-1;
            if(len==3)
            {
               // return 0;
            }
            double ans=1e9;
            for(int x=l+1;x<=r;x++)
            {
                if(x==l+1)
                {
                    ans=max(ans,cost(l+1,r)+dp[l+1][r]);
                }
                else if(x==r-1)
                {
                    ans=max(ans,cost(l,x)+cost(r,x)+dp[l][x]+dp[x][r]);
                }
            }
          dp[l][r]=ans;
        }
    }
 cout<<dp[1][n]<<endl;
    
    
    
    
    
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