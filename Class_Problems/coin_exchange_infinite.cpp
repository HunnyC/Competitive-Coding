#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        int dp[n+1][amount+1];
        for(int i=n;i>=0;i--)
        {
            for(int j=0;j<=amount;j++)
            {
                if(i==n)
                {
                    if(j==0)
                    dp[i][j]=1;
                    else
                    dp[i][j]=0;
                }
                else
                {
                    int ans=0;
                    if(dp[i+1][j])
                    ans+=dp[i+1][j];

                    if(j>=coins[i]&&dp[i][j-coins[i]])ans+=dp[i][j-coins[i]];
                    dp[i][j]=ans;

                }
            }

        }
        return dp[0][amount];
    }
};