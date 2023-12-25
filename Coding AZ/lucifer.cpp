#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll=long long int;
ll mod=1e9+7;
string l,r;
int n;
int tt;
//int testcase[20][2][2][];
ll dp[12][2][2][100];
ll t;
bool isprime(int a)
{
    if(a==1)return 0;
    for(int i=2;i*i<=a;i++)
    {
        if(a%i==0)return 0;
    }
    return 1;
}
ll rec(int level,int t1,int t2,ll diff)
{
    if(level==n)
    {
        if(diff>0&&isprime(diff))
        {
               return 1;
        }
        else return 0;
    }
    if(dp[level][t1][t2][diff]!=-1)return dp[level][t1][t2][diff];
    ll ans=0;
    int lo=0,hi=9;
    if(t1)lo=l[level]-'0';
    if(t2)hi=r[level]-'0';

    for(int i=lo;i<=hi;i++)
    {
      int f1=t1,f2=t2;
      if(i!=l[level]-'0')f1=0;
      if(i!=r[level]-'0')f2=0;
      
      if(level%2)
      {
          ans+=rec(level+1,f1,f2,diff-i);
      }
      else
      {
        ans+=rec(level+1,f1,f2,diff+i);
      }
    }


    return dp[level][t1][t2][diff]=ans;


}


void solve()
{  
    cin>>l>>r;
    if(r.size()%2==1)r='0'+r;
   n=r.size();

   string st="";
  for(int i=0;i<n-(int)l.size();i++)
  {
     st+='0';
  }
  l=st+l;
  
  memset(dp,-1,sizeof(dp));
  //cout<<l<<" "<<r<<endl;
  cout<<rec(0,1,1,0);

    
    
    
    
}

int main()
{
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
    for(tt=1;tt<=t;tt++)
    {
        solve();
        cout<<endl;
    }
  
}