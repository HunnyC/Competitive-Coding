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
    int a[n];
    unordered_map<int,int>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        m[a[i]]++;
    }
    int mx=0;
    ll sum=0;
    for(auto it:m)
    {
        mx=max(mx,it.second);
        sum+=it.second;

    }
    sum-=mx;
    if(mx>=sum)
    {
        cout<<2*(sum);

    }
    else

    {
        cout<<n;
        
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