#include <bits/stdc++.h>
#define endl '\n'
const int mod = (1e9 + 7);
using ll = long long int;
using namespace std;
ll binary(ll a, ll b, ll p)
{
    ll ans = 1;
    if (b == 0)
        return 1;
    if (a == 1)
        return 1;
    while (b)
    {
        if (b % 2 == 1)
        {
            ans = ((ans % p) * (a % p)) % p;
        }
        a = ((a % p) * (a % p)) % p;
        b /= 2;
    }
    return ans;
}
void print(stack<char> s)
{   
    cout<<"current stack: "; 
    while(s.size()!=0)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    
    
}
ll func(ll x,string &s,string st,ll y,string str)
{  
    stack<char>sck;
    ll ans=0;
    for(int i=0;i<s.size();i++)
    {
        if(sck.empty())
        {
            sck.push(s[i]);
            continue;
        }
        
        
         
           //cout<<"sl"<<" "<<sl<<endl;
        if(st[0]==sck.top()&&s[i]==st[1])
        {
            ans+=x;
         
           
            sck.pop();
        }
        else
        {
            sck.push(s[i]);
        }
    }
     string sdf="";

    
    while(!sck.empty())
    {
        
        char c=sck.top();
        sdf+=c;
        sck.pop();
      
    }
    reverse(sdf.begin(),sdf.end());
     for(int i=0;i<sdf.length();i++)
    {   
       
        if(sck.empty())
        {
            sck.push(sdf[i]);
            
            continue;
        }
        
      
       
        if(str[0]==sck.top()&&sdf[i]==str[1])
        {
            ans+=y;
           
            sck.pop();
        }
        else
        {
            sck.push(sdf[i]);
        }
    }
    
    return ans;
}
void solve()
{
    string s;
    ll x, y;

    cin >> s >> x >> y;
     if(x>y)
     {
         cout<<func(x,s,"ab",y,"ba");
     }
     else 
     cout<<func(y,s,"ba",x,"ab");

    
    

    

  
  
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        cout << endl;
    }
}