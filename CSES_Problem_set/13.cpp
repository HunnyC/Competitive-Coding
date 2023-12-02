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
void solve()
{
    string s;
    cin>>s;
    if((int)s.size()%2)
    {
        unordered_map<char,int>m;
        int c=0;
        for(int i=0;i<(int)s.size();i++)
        {
            m[s[i]]++;
        }
        char g;
        for(auto it:m)
        {
            if(c>1){cout<<"NO SOLUTION";return;}
            if(it.second%2){
                g=it.first;c++;
            }
        }
        int cnt=0;
        m[g]--;
        for(auto &it:m)
        {
             for(int i=0;i<it.second/2;i++)
             {
                cout<<it.first;
                cnt++;
             }
             m[it.first]=it.second-it.second/2;
             
        }
        deque<char>d;
        for(auto it:m)
        {
             for(int i=0;i<it.second;i++)
             {
                d.push_front(it.first);
             }
        }
        int i=0;
        cout<<g;
        for(auto it:d)
        {   
           
            cout<<it;
           
            
        }
    }
    else
    {
            unordered_map<char,int>m;
        int c=0;
        for(int i=0;i<(int)s.size();i++)
        {
            m[s[i]]++;
        }
        char g;
        for(auto it:m)
        {
            if(c>0){cout<<"NO SOLUTION";return;}
            if(it.second%2){
                g=it.first;c++;
            }
        }
        for(auto &it:m)
        {
             for(int i=0;i<it.second/2;i++)
             {
                cout<<it.first;
             }
             m[it.first]=it.second-it.second/2;
             
        }
          deque<char>d;
        for(auto it:m)
        {
             for(int i=0;i<it.second;i++)
             {
                d.push_front(it.first);
             }
        }
        for(auto it:d)
        {
            cout<<it;
        }
    }
   
    
    
    
    
    
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