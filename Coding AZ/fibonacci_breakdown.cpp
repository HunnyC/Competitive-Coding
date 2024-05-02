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

vector<ll>fb(51);
void func()
{
    fb[0]=-1;
    fb[1]=-1;
    for(int i=2;i<=50;i++)
    {
        fb[i]=fb[i-1]+fb[i-2];
    }
}
void solve()
{

    ll n;
    cin>>n;
    //  for(int i=0;i<=50;i++)cout<<"Fb : "<<fb[i]<<endl;
    sort(fb.begin(),fb.end());
    int ans=0;
    while(n>0)
    { 
        auto it=lower_bound(fb.begin(),fb.end(),-n);
        n+=(*it);
        ans++;


        

         
    }
    cout<<ans;


    

    



}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    func();
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}