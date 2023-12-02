#include<bits/stdc++.h>
using namespace std;
int main()
{
   int a=0;
   string s;
   cin>>s;
   int j=1;
   for(int i=1;i<(int)s.size();i++)
   {
       if(s[i]==s[i-1])
       {
        j++;
       }
       else
       {
         a=max(a,j);
         j=1;
       }

   }
   a=max(a,j);
   cout<<a;

   return 0;
}