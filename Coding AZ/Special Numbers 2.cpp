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
string l,r;
int n;
ll dp[15][2][2][100005];
ll rec(int index,int tho,int thi,ll sum)
{
    if(index==n)
    {
        if(sum==0)return 1;
        return 0;
    }
    if(dp[index][tho][thi][sum]!=-1)return dp[index][tho][thi][sum];
    ll ans=0;
    int lo=0,hi=9;
    if(tho)
    lo=l[index]-'0';
    if(thi)
    hi=r[index]-'0';
    for(int i=lo;i<=hi;i++)
    {
        int lt=tho,lh=thi;
        if(l[index]-'0'!=i)lt=0;
        if(r[index]-'0'!=i)lh=0;
        ans+=rec(index+1,lt,lh,(sum%i+(binary(i,i,i))));



    }
   return dp[index][tho][thi][sum]=ans;

}
void solve()
{
    cin>>l>>r;
    n=r.size();
    int t=n-l.size();
    string temp="";
    while(t--)
    {
        temp+='0';
    }
    l=temp+l;
    cout<<rec(0,1,1,0);

    
    
    
    
    
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