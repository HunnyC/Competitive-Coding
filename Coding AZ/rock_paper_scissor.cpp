#include <bits/stdc++.h>
using namespace std;

map<int, int> ma;
map<int, char> rm;
int arr[1100];
int dp[1100][3][1100];
int n, k;
string s = "";
string a = "";
int back[1100][3][1100];
int result(int a, int b)
{
    if (a == 0)
    {
        if (b == 2)
        {
            return 1;
        }
        return 0;
    }
    if (a == 1)
    {
        if (b == 0)
        {
            return 1;
        }
        return 0;
    }

    if (b == 1)
    {
        return 1;
    }
    return 0;
}
// int result(int m,int cm)
// {
//     return cm==(m+1)%3;

// }
int rec(int level, int last, int kvalue)
{
    if (kvalue < 0)
        return -1e9;
    if (level == n)
    {
        return 0;
    }
    if (dp[level][last][kvalue] != -1)
    {
        return dp[level][last][kvalue];
    }
    int ans = 0;
    back[level][last][kvalue] = -1;
    for (int x = 0; x < 3; x++)
    {
        int temp = result(x, arr[level]) + rec(level + 1, x, kvalue - ((x == last) ? 0 : 1));
        ans = max(ans, temp);
        if (ans == temp)
        {
            back[level][last][kvalue] = x;
        }
    }

    return dp[level][last][kvalue] = ans;
}

void generate(int level, int last, int kvalue)
{
    if (level == n)
    {
        return;
    }
    int x = back[level][last][kvalue];
    a += rm[x];
    generate(level + 1, x, kvalue - ((x == last) ? 0 : 1));
}

void solve()
{
    cin >> n >> k;
    cin >> s;
    a = "";
    for (int i = 0; i < s.size(); i++)
    {
        arr[i] = ma[s[i]];
    }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < 3; j++)
            for (int z = 0; z <= k; z++)
                dp[i][j][z] = -1;

    int c = 0;
    int ans = 0;
    for (int i = 0; i < 3; i++)
    {
        int t = rec(0, i, k);
        if (t > ans)
        {
            ans = t;
            c = i;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (rec(0, i, k) == ans && back[0][i][k] == i)
        {
            c = i;
        }
    }
    cout << ans << endl;

    generate(0, c, k);

    cout << a << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ma['P'] = 2;
    ma['R'] = 1;
    ma['S'] = 0;
    rm[2] = 'P';
    rm[1] = 'R';
    rm[0] = 'S';
    int t;
    cin >> t;
    while (t--)
        solve();
}