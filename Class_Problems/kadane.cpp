/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        
    }
    vector<int>dp(n+1);
    int ans=0;
    for(int i=0;i<n;i++)
    {
       if(!i)dp[i]=a[i];
       else
       {
           dp[i]=max(dp[i-1]+a[i],a[i]);
           
       }
       ans=max(ans,dp[i]);
    }
   cout<<ans<<endl;
    return 0;
}
