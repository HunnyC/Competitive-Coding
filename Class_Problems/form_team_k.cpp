#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long int;

//greedy problem

void solve()
{

    int n, k;
    cin >> n >> k;
    // first is speed ,second is efficiency
    pair<int, int> arr[n];
    sort(arr, arr + n);
    reverse(arr, arr + n);
    priority_queue<int, vector<int>, greater<int>> q;
    int ans = 0;
    int top_k = 0;
    for (int i = 0; i < n; i++)
    {
        q.push(arr[i].second);
        top_k+=arr[i].second;
        if(q.size()>k)
        {
            int x= q.top();q.pop();
            top_k-=x;
        }
        ans=max(ans,top_k*arr[i].first);

    }
    cout<<ans<<endl;

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
}