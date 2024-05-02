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
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int ans=0;
    queue<int>q;
    for(int i=0;i<n;i++)
    {
        if(a[i] != ((int)q.size()%2 ? 0:1))
        {
            ans++;
            q.push(i+k-1);
        }
        if(!q.empty()&&q.front()<=i)q.pop();

    }
    if(q.empty())
    {
        cout<<ans;
    }
    else cout<<0;
    




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