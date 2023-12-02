//optimise version
#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
int n,m;
int a[1011][1011];
int dp[100][100][100];
int done[100][100][100];
bool check(int r,int c)
{
    if(r>=n||c>=m)return 0;
    return 1;
}

int rec(int r1,int c1,int r2)   //r1+c1=c2+r2 state space reduction

{   
    int c2=r1+c1-r2;
    if((!check(r1,c1))||(!check(r2,c2)))return -1e9;
    
    if(r1==n-1&&c1==m-1&&r2==n-1&&c2==m-1)return a[n-1][m-1];
    
    if(done[r1][c1][r2]!=-1)return dp[r1][c1][r2];
    
    done[r1][c1][r2]=1;
    
    int ans=((r1==r2&&c1==c2)?a[r1][c1]:(a[r1][c1]+a[r2][c2]));
    ans=ans+max({rec(r1+1,c1,r2+1),rec(r1+1,c1,r2),rec(r1,c1+1,r2+1),rec(r1,c1+1,r2)});
    return dp[r1][c1][r2]=ans;
    
    
    
    
    
}


void solve()
{
    cin>>n>>m;
    memset(done,-1,sizeof(done));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<rec(0,0,0);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}






















// #include<bits/stdc++.h>
// using namespace std;
// using ll=long long int;
// int n,m;
// int a[1011][1011];
// int dp[100][100][100][100];
// int done[100][100][100][100];
// bool check(int r,int c)
// {
//     if(r>=n||c>=m)return 0;
//     return 1;
// }

// int rec(int r1,int c1,int r2,int c2)
// {
//     if((!check(r1,c1))||(!check(r2,c2)))return -1e9;
    
//     if(r1==n-1&&c1==m-1&&r2==n-1&&c2==m-1)return a[n-1][m-1];
    
//     if(done[r1][c1][r2][c2]!=-1)return dp[r1][c1][r2][c2];
    
//     done[r1][c1][r2][c2]=1;
    
//     int ans=((r1==r2&&c1==c2)?a[r1][c1]:(a[r1][c1]+a[r2][c2]));
//     ans=ans+max({rec(r1+1,c1,r2+1,c2),rec(r1+1,c1,r2,c2+1),rec(r1,c1+1,r2+1,c2),rec(r1,c1+1,r2,c2+1)});
//     return dp[r1][c1][r2][c2]=ans;
    
    
    
    
    
// }


// void solve()
// {
//     cin>>n>>m;
//     memset(done,-1,sizeof(done));
//     for(int i=0;i<n;i++)
//     {
//         for(int j=0;j<m;j++)
//         {
//             cin>>a[i][j];
//         }
//     }
//     cout<<rec(0,0,0,0);
// }

// signed main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);cout.tie(0);
//     solve();
// }