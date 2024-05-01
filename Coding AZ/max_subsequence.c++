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

//nlogn 
void solve2()
{
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  {
    cin>>a[i];
  }
  vector<int>lis;
  int inserted[n];
  for(int i=0;i<n;i++)
  {
    if(lis.empty()||lis.back()<a[i])
    {
      lis.push_back(a[i]);
      inserted[i]=lis.size();
    }
    else
    {
      auto it=lower_bound(lis.begin(),lis.end(),a[i]);
      *it=a[i];
      inserted[i]=it-lis.begin()+1;
    }
  }
  for(auto it:inserted)
  {
    cout<<it<<" ";
  }
  cout<<endl;
  vector<int> finalans;
  int curlen=lis.size();
  for(int i=n-1;i>=0;i--)
  {
    if(inserted[i]==curlen)
    {
        finalans.push_back(a[i]);
        curlen--;
    }
  }
  reverse(finalans.begin(),finalans.end());
  for(auto it:finalans)
  {
    cout<<it<<" ";
  }
  cout<<endl;
  cout<<"Max length "<<lis.size()<<endl;

}
int main()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);cout.tie(0);
   int t=1;
  //  cin>>t;
   while(t--)
   {
       solve2();
      // cout<<endl;
   }
}