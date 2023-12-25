#include<bits/stdc++.h>
#define endl '\n'
const int mod = (1e9+7);
//using ll = long long int;
#define int long long
using namespace std;

// string l,r;
// int d;
// int n;
// int dp[100][2][2][100];
// int rec(int level,int tho,int thi ,int sumd)
// {
//     if(level==n)
//     {
//         if(sumd==0)return 1;
//         return 0;
//     }
//     if(dp[level][tho][thi][sumd]!=-1)return dp[level][tho][thi][sumd];
//     int ans=0;
//     int lo=0;
//     if(tho==1)
//     {
//         lo=l[level]-'0';
//     }
//     int hi=9;
//     if(thi==1)
//     {
//         hi=r[level]-'0';
//     }
//     for(int i=lo;i<=hi;i++)
//     {
//         int ntho=tho;
//         int nthi=thi;
//         if(i!=(l[level]-'0'))ntho=0;
//         if(i!=(l[level]-'0'))nthi=0;

//         ans+=rec(level+1,ntho,nthi,sumd);
//         ans%=mod;
        
//     }
//     return dp[level][tho][thi][sumd]=ans;

// }
// void solve()
// {
//     cin>>l>>r;
//     cin>>d;
//     n=r.size();
//     string temp="";
//     int t=r.size()-l.size();
//     while(t--)
//     {
//         temp+='0';
//     }
//     l+=temp;
//     memset(dp,-1,sizeof(dp));
//     cout<<rec(0,1,1,0);
   
    

// }
string l="",r="";
int d;
int dp[10003][2][2][103];
int n;
int rec(int level, int dlo,int dhi,int sum)
{
    if(level==n)
    {
        if(sum==0)
        return 1;
        return 0;

    }
    if(dp[level][dlo][dhi][sum]!=-1)return dp[level][dlo][dhi][sum];
    int lo=0;
    int hi=9;
    if(dlo==1)
    lo=l[level]-'0';
    if(dhi==1)
    hi=r[level]-'0';
    int ans=0;
    for(int i=lo;i<=hi;i++)
    {   
        int dl=dlo,dh=dhi;
        if(l[level]-'0'!=i)dl=0;
        if(r[level]-'0'!=i)dh=0;
        ans+=rec(level+1,dl,dh,(sum+i)%d);
        ans%=mod;
    }

    return dp[level][dlo][dhi][sum]=ans;

}
void solve()
{
    cin>>r;
    cin>>d;
    l="";
    memset(dp,-1,sizeof(dp));
    string lr="";
    n=r.size();
    int temp=n-1;

    while(temp--)
    {
        lr+='0';
    }
    l+=lr;
    l+='1';
    //cout<<l<<" "<<r<<endl;
    cout<<rec(0,1,1,0);


}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
  //  cin>>t;
    while(t--)
    {
        solve();
        cout<<endl;
    }
}