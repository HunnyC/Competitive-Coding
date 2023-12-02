#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a;
    cin>>a;
    cout<<a<<" ";
    while(a!=1)
    { 
      if(__builtin_popcount (a)==1)
      { 
        a/=2;
        while(a!=1)
        {
            cout<<a<<" ";
            a/=2;
        }
        cout<<1;
        return 0;
      }
      if(!(a%2))
      {
        a/=2;
      } 
      else{
        a*=3;
        a+=1;
      }
      cout<<a<<" ";
    }
    return 0;
}