#include<bits/stdc++.h>
#define endl '\n'
const int mod = (1e9+7);
using ll = long long int;
using namespace std;
ll binary(ll a,ll b, ll p)
{  ll ans=1;
if(b==0)return 1;
if(a==1)return 1;
   while(b)
   {
       if(b%2==1)
       {
         ans = ((ans % p) * (a % p)) % p;
       }
       a = ((a % p) * (a % p)) % p;
       b/=2;
   }
 return  ans;
}
ll powi(ll a,ll b,ll p)
{
    if(b==0)
    return 1;
    if(b%2)
    {
       ll ans=(a*powi(a,b-1,p))%mod;
       return ans;
    }
    else
    {
          ll ans=powi(a,b/2,p);
          return (ans*ans)%mod;
    }
}

       

vector<vector<char>>v;
vector<int>st;
bool check(int r,int c)
{  
   
        for(int i=0;i<r;i++)
    {  
        if(st[i]==c)
        {
            
            return 0;
        }
        if(abs(c-st[i])==abs(r-i))
        {
           
            return 0;
        }
        //if(st[i]==c||abs(c-st[i])==abs(r-i)){ cout<<"*"<<endl;return 0;}
    }
    return 1;

    

}
int rec(int level)
{
     if(level==8)
     {  
        if(st.size()==8)return 1;
 
        return 0;
      

     }
     int ans=0;
     for(int col=0;col<8;col++)
     {   
         int t=check(level,col);
         
         if(v[level][col]=='.'&&t==1)
         {  
           st.push_back(col);
            ans+=rec(level+1);
         
            st.pop_back();
         }
     }
    
     return ans;

}
void solve()
{  
   
   for(int i=0;i<8;i++)
   {
    vector<char>v1;

    for(int j=0;j<8;j++)
    {
        char c;
        cin>>c;
        v1.push_back(c);

    }
    v.push_back(v1);

   }
   cout<<rec(0);










}
   
    
    
    
    
    

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
        cout<<endl;
    }
}