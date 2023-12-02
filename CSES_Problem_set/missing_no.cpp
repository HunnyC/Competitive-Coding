#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int s,a,i;
    cin>>a;
    s=a*(a+1)/2;
    i=0;
    a-=1;
    while(a--)
    {
        int t;
        cin>>t;
        i+=t;
    }
   cout<<s-i;
    return 0;
}