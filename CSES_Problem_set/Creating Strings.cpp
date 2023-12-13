#include<bits/stdc++.h>
#define endl '\n'
const int mod = (1e9+7);
using ll = long long int;
using namespace std;

vector<int>v;
set<string>g;
string s="";
int n;
bool check(int i)
{
    for(int j=0;j<(int)(v.size());j++)
    if(v[j]==i)return 0;
    return 1;

}
int cnt=0;

void print(int i)
{  
    
    if(i==(int)s.size())
    {  
        string st="";
        for(int j=0;j<int(v.size());j++)
        {
            st+=s[v[j]];
        }
        g.insert(st);
        
        
    }
    for(int j=0;j<n;j++)
    {
         if(check(j))
         {
              v.push_back(j);
              print(i+1);
              v.pop_back();
         }
    }


}

void solve()
{
   
   cin>>s;
   n=(int)s.size();
   print(0);
   cout<<g.size()<<endl;
   for(auto it:g)
   {
    cout<<it<<endl;
   }
    
    
    
    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
   // cin>>t;
    while(t--)
    {
        solve();
        cout<<endl;
    }
}