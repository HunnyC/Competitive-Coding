#include<bits/stdc++.h>
using namespace std;

int queen[100];
int n;
bool check(int row,int column)
{
    for(int i=0;i<row;i++)
    {
        int prow=i;
        int pcol=queen[i];
        if(pcol==column||abs(pcol-column)==abs(prow-row))return 0;
    }

    return 1;
}

int rec(int level)
{   
    static int c=1;
    if(level==n)
    {  
        cout<<"index  "<<c<<": ";
        c++;
        for(int i=0;i<n;i++)
        {
            cout<<queen[i]<<" ";
        }cout<<endl;
        return 1;
    }
   int ans=0;
    for(int col=0;col<n;col++)
    {
        if(check(level,col))
        {
        
         queen[level]=col;
         ans+=rec(level+1);
         queen[level]=-1;

        }
    }
    return ans;
}









void solve(){

cin>>n;
 memset(queen,-1,sizeof(queen));
 cout<<rec(0);
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
 
    
  
}