#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using ll=long long int;
ll mod=1e9+7;
bool isprime(int a)
{
    if(a<=1)return 0;
    for(int i=2;i*i<=a;i++)
    {
        if(a%i==0)return 0;
    }
    return 1;
}
string l,r;
int n;
int dp[54][2][2][2][2][500][500][2];
int rec(int level,int t1,int t2,int f1,int f2,int s1,int s2,int f)
{
    if(level==n)
    {
        if(f==1&&s2>s1&&isprime(s2+s1))return 1;
        return 0;

    }
    if(dp[level][t1][t2][f1][f2][s1][s2][f]!=-1)return dp[level][t1][t2][f1][f2][s1][s2][f];
    int ans=0;
    int lo=0,hi=9,l2=0,hi2=9;
    if(t1)lo=l[level]-'0';
    if(t2)hi=r[level]-'0';
    if(f1)l2=l[level]-'0';
    if(f2)hi2=r[level]-'0';
    for(int i=lo;i<=hi;i++)
    {
        for(int j=l2;j<=hi2;j++)
        {
            int o1=t1,o2=t2,x1=f1,x2=f2;
            if(i!=l[level]-'0')o1=0;
            if(i!=r[level]-'0')o2=0;
            if(j!=l[level]-'0')x1=0;
            if(j!=r[level]-'0')x2=0;
         
            if(f==0)
            {        
                

                   if(i==j)
                     ans=(ans*1LL+rec(level+1,o1,o2,x1,x2,s1+i,s2+j,0)*1LL)%mod;
                     else if(j>i)
                     {
                          ans=(ans*1LL+rec(level+1,o1,o2,x1,x2,s1+i,s2+j,1)*1LL)%mod;
                     }
            }
            else 
            {
                ans=(ans*1LL+rec(level+1,o1,o2,x1,x2,s1+i,s2+j,1)*1LL)%mod;
            }
        }
    }

    



    return dp[level][t1][t2][f1][f2][s1][s2][f] = ans;

}



void solve()
{  
   cin>>r;
   n=r.size();
   l="";
   for(int i=0;i<n;i++)
   {
    l+='0';
   }
   memset(dp,-1,sizeof(dp));
   cout<<rec(0,1,1,1,1,0,0,0);



    
    
    
}

int main()
{
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int t=1;
	//cin>>t;
    int tt;
    for(tt=1;tt<=t;tt++)
    {
        solve();
        cout<<endl;
    }
  
}