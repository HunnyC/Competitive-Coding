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
    ll a[n];
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];

    }
    sort(a,a+n);
    sum-=a[n-1];
    if(sum<=a[n-1])
    {
        cout<<a[n-1]-sum;
    }
    else
    {
        cout<<(sum-a[n-1])%2;
    }
    
    







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