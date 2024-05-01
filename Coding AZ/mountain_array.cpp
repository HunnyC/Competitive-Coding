#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    //finding lis left;
    vector<int>lis,dp1(n+1),dp2(n+1),lds;
    for(int i=0;i<n;i++)
    {
        if(lis.empty()||lis.back()<a[i])
        {
            lis.push_back(a[i]);
            dp1[i]=lis.size();
        }
        else 
        {
            auto it=lower_bound(lis.begin(),lis.end(),a[i]);
            *it=a[i];
            dp1[i]=it-lis.begin()+1;

        }
    }
    int ans=0;
    for(int i=n-1;i>=0;i--)
    {
        if(lds.empty()||lds.back()>a[i])
        {
             lds.push_back(a[i]);
             dp2[i]=lds.size();
        }
        else
        {
            auto it=lower_bound(lds.begin(),lds.end(),a[i]);
             *it=a[i];
            dp2[i]=it-lds.begin()+1;


        }
        if(dp1[i]>=2&&dp2[i]>=2)
        {
            ans=max(ans,dp1[i]+dp2[i]-1);
        }


    }

   cout<<ans<<endl;
 
 
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    t=1;
    cin>>t;
    while(t--)
    {
        solve();

    }
}