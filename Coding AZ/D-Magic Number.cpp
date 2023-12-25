#include<bits/stdc++.h>
#define endl '\n'
const int mod = (1e9+7);
using ll = long long int;

using namespace std;


string l="",r="";

ll dp[10013][2][2][2003];
ll n;
int m,d;
ll rec(int level, int dlo,int dhi,int rem)
{
    if(level==n)
    {
        if(rem==0)
        return 1;
        else return 0;

    }
    if(dp[level][dlo][dhi][rem]!=-1)return dp[level][dlo][dhi][rem];
    int lo=0;
    int hi=9;
    if(dlo==1)
    lo=l[level]-'0';
    if(dhi==1)
    hi=r[level]-'0';
    ll ans=0;
    for(int i=lo;i<=hi;i++)
    {   
        int dl=dlo,dh=dhi;
        if((level)%2==1)
        {
               if(i!=d)continue;
        }
        else
       {
            if(i==d)continue;
       }

        if(l[level]-'0'!=i)dl=0;
        if(r[level]-'0'!=i)dh=0;
        ans=(ans+rec(level+1,dl,dh,(rem*10+i)%m))%mod;
       
    }

    return dp[level][dlo][dhi][rem]=ans;

}
void solve()
{   
    cin>>m>>d;
    cin>>l>>r;
    
    
    memset(dp,-1,sizeof(dp));
    string lr="";
    n=r.size();
    int temp=n-l.size();

    while(temp--)
    {
        lr+='0';
    }
    l=lr+l;
    
    //cout<<l<<" "<<r<<endl;
    cout<<rec(0,1,1,0);


}
signed main()
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