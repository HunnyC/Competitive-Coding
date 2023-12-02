#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        ll r,c;
        cin>>r>>c;
        r--;
        c--;
        if(r==c)
        {
           cout<<1LL*(r*(r+1)+1)<<endl;
        }
        else if(c>r)
        {
              ll s=c-r;
               r+=s;
               ll v=1LL*(r*(r+1)+1);
               if(c%2==0)
               {
                     cout<<(v+s)<<endl;
               }
               else
               {
                       cout<<(v-s)<<endl;
               }
        }
        else
        {
                    ll s=r-c;
               c+=s;
               ll v=1LL*(r*(r+1)+1);
               if(c%2!=0)
               {
                     cout<<(v+s)<<endl;
               }
               else
               {
                       cout<<(v-s)<<endl;
               }
        }
    }
   return 0;
}