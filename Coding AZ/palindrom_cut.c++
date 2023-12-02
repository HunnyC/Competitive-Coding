#include<bits/stdc++.h>
using namespace std;



int n;
int dp1[1001][1001];
int dp2[1001];
string s;
int rec1(int l,int r)
{
    if(l>=r)
    {
        return 1;
    }
    if(dp1[l][r]!=-1)
    return dp1[l][r];

    dp1[l][r]=(s[l-1]==s[r-1])&&rec1(l+1,r-1);
    return dp1[l][r];
}
int rec2(int i)
{
    if(i==0)
    return -1;
    if(dp2[i]!=-1)
    return dp2[i];

    int ans=1e9;
    for(int j=0;j<i;j++)
    {
        if(rec1(j+1,i))
        {
            ans=min(ans,1+rec2(j));
        }
    }
    cout<<"i"<<" "<<i<<" "<<"ans"<<" "<<ans<<endl;
    return dp2[i]=ans;


}
void solve()
{
   cin>>n;
   cin>>s;
   memset(dp1,-1,sizeof(dp1));
   memset(dp2,-1,sizeof(dp2));

   cout<<rec2(n);
 

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    t=1;
    while(t--)
    {
        solve();

    }
}