#include <bits/stdc++.h>
using namespace std;

#define ll int64_t
vector<int>in;
int dp[101][100005];
int n;
int rec(int level,int left,vector<int>&v)
{
    if(left<0)return 0;
    if(level==n)
    {
        if(left==0)return 1;
        return 0;
    }
    if(dp[level][left]!=-1)
    {
        return dp[level][left];
    }
    int ans=0;
    ans=rec(level+1,left,v)||rec(level+1,left-v[level],v);
    return dp[level][left]=ans;
    
}
void func(int level,int left,vector<int>&arr)
{
    if(level==n)
    {
        return;
    }
    if(rec(level+1,left,arr))
    {
        func(level+1,left,arr);
    }
    else 
    {  
        in.push_back(arr[level]);
        func(level+1,left-arr[level],arr);
    }
 }
vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries) {
    // Write code here.
    memset(dp,-1,sizeof(dp));
    vector<vector<int>>r;
    n=arr.size();
    for(auto it:queries)
    {
        if(rec(0,it,arr))
        {
            func(0,it,arr);
        }
        else
        {
            in.push_back(-1);
        }
        r.push_back(in);
        in.clear();
    }
    
    
    return r;
}

#include <bits/stdc++.h>
using namespace std;
void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)cin >> queries[i];
    auto ans = subset_queries(arr, queries);

    // checker.
    if (ans.size() != Q) {
        cout << 101 << endl;
        return;
    }
    for (int i = 0; i < Q; i++) {
        auto x = ans[i];
        if (x.size() == 0) {
            cout << 101 << endl;
            continue;
        }
        if (x.size() == 1 && x[0] == -1) {
            cout << -1 << endl;
            continue;
        }
        ll sum = 0, p = -10;
        for (auto y : x) {
            if (y < 0 || y >= N || p >= y ) { // valid 0-indexed.
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }
        if (sum == queries[i]) {
            cout << 1 << endl;
        }
        else cout << 101 << endl;
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}