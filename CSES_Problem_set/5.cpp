#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(0);

   ll n;
   cin>>n;
   if(n==1){cout<<1;return 0;}
   vector<int>v;
   if(n<=3)cout<<"NO SOLUTION";
   else if (n==4) cout<<2<<" "<<4<<" "<<1<<" "<<3<<" ";
   else
   {
      while(n>5)
      {  
        if(n%2!=0)
        cout<<n<<" ";
        else 
        v.push_back(n);
        
        n--;

      }
      cout<<5<<" "<<2<<" "<<4<<" "<<1<<" "<<3<<" ";
      for(int i=0;i<(int)v.size();i++)
      cout<<v[i]<<" ";
   }
   return 0;
}