#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(0);

    ll n;
    cin>>n;
    
   ll s=n*(n+1)/2;

   if(s%2==0)
   {
    cout<<"YES"<<endl;
    ll s1=0;
    int i=0;
    vector<ll>v;
    vector<ll>v1;
    while(n!=0)
    {
        if(s1+n<=s/2)
        {
           s1+=n;
          v1.push_back(n);
           n--;
           
        }
        else
        {
            v.push_back(n);
            n--;
        }
           
        
        
    }
    cout<<v1.size()<<endl;
       for(int i=0;i<(int)v1.size();i++)
    {
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    cout<<v.size()<<endl;
    for(int i=0;i<(int)v.size();i++)
    {
        cout<<v[i]<<" ";
    }

   }
   else 
   {
    cout<<"NO";
   }
   return 0;
}