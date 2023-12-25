#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll=long long int;
string l,r;
ll n=64;
string a,b;
string tobool(ll n)
{
    string s="";
   
    if(n==0)s+='0';
    
    while(n)
    {
        if(n%2)s+='1';
        else s+='0';
        n/=2;
    }
    reverse(s.begin(),s.end());
    
    return s;
    
}
ll dp[65][2][2][2][2];
ll rec(int level,int flo,int fh,int slo,int sh)
{
    if(level==n)
    return 0;
    if(dp[level][flo][fh][slo][sh]!=-1)return dp[level][flo][fh][slo][sh];
    ll ans=0;
    ll v=(1LL<<(n-level-1));
    int al=0,ah=1;
    int bl=0,bh=1;
    if(flo)al=a[level]-'0';
    if(fh)ah=b[level]-'0';
    if(slo)bl=a[level]-'0';
    if(sh)bh=b[level]-'0';
    for(int i=al;i<=ah;i++)
    {  
       
        
        for(int j=bl;j<=bh;j++)
        {
           int flo1=flo,fh1=fh,slo1=slo,sh1=sh;
           if(i!=a[level]-'0')flo1=0;
           if(i!=b[level]-'0')fh1=0;
           if(j!=a[level]-'0')slo1=0;
           if(j!=b[level]-'0')sh1=0;
           ans=max(ans,rec(level+1,flo1,fh1,slo1,sh1)+v*(i^j));
           
           
            
        }
    }
    return dp[level][flo][fh][slo][sh]=ans;
    
}
void solve()
{
    ll x,y;
    cin>>x>>y;
    a=tobool(x);
    b=tobool(y);
    
    int dif=(max(a.size(),b.size())-min(a.size(),b.size()));
    string st="";
    n=b.size();
    while(dif--)
    {
        st+='0';
    }
    if(a.size()>b.size())
    {
        b=st+b;
        n=a.size();
    }else a=st+a;
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,1,1,1,1);
    //cout<<a<<" "<<b;
    
    
    
    
    
}

int main()
{
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ll t=1;
	cin>>t;
    while(t--)
    {
        solve();
        cout<<endl;
    }
}