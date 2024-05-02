#include <bits/stdc++.h>
#define endl '\n'
const int mod = (1e9 + 7);
using ll = long long int;
using namespace std;
ll binary(ll a, ll b, ll p)
{
    ll ans = 1;
    if (b == 0)
        return 1;
    if (a == 1)
        return 1;
    while (b)
    {
        if (b % 2 == 1)
        {
            ans = ((ans % p) * (a % p)) % p;
        }
        a = ((a % p) * (a % p)) % p;
        b /= 2;
    }
    return ans;
}
void solve()
{
    int n;
    cin>>n;
    pair<ll,ll>a[n];
    pair<ll,int>b[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first;
        b[i].first=a[i].first;
        a[i].second=1;
        b[i].second=i;
    }
    sort(b,b+n);
    
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        int v=b[i].first;
        int ind=b[i].second;
        ans+=a[ind].second;
        if(ind+1<n)
        {
            a[ind+1].second=max(a[ind+1].second,a[ind].second+1);

        }
        if(ind-1>=0)
        {
            a[ind-1].second=max(a[ind-1].second,a[ind].second+1);
        }


        


    }
    cout<<ans;



}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}