#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(0);

   ll n;
   cin>>n;
   ll ans=0;
   ll a,b;
    n--;
    cin>>a;
   while(n--)
   {
       cin>>b;
       if(b<a){ans+=(a-b);
       }
       else
       {
        a=b;
       }
   }
cout<<ans;
   return 0;
}