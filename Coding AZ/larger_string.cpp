#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll=long long int;
ll mod=1e9+7;
string r;
int n;
int tt;
int testcase[100010][2][2];
ll dp[100010][2][2];
ll t;
ll rec(int level,int t1,int t2)
{
      if(level==n)
      {
        if(t1==0&&t2==0)return 1;else
        return 0;
      }
      if(testcase[level][t1][t2]==tt)return dp[level][t1][t2];
      ll ans=0;

      for(char c='A';c<='Z';c++)
      {
          if(t1==1&&c<r[level])continue;
          int f1=t1;
          if(c>r[level])f1=0;
          int f2;
          if(c==r[level])
          {
            f2=t2;
          }else  if(c>r[level])
          {
              f2=0;
          }else f2=1;

          ans=(ans+rec(level+1,f1,f2))%mod;
      }
     testcase[level][t1][t2]=tt;
     return dp[level][t1][t2]=ans;

}


void solve()
{  
   
    cin>>r;
    n=r.size();
    cout<<rec(0,1,1);

    
    
    
    
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