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
    pair<int,int>a[n];
    for(int i=0;i<n;i++)cin>>a[i].first>>a[i].second;
    sort(a,a+n);
    ll ans=1;
    int last=a[0].second;
    for(int i=1;i<n;i++)
    { 
        if(a[i].first>last)
        {
            ans++;
            last=a[i].second;
        }
        else
        {
            last=max(last,a[i].second);
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