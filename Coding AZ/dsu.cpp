#include<bits/stdc++.h>
using namespace std;

class disjointset{
    vector<int> ranks,parents,size;
    public:
    disjointset(int n){
        ranks.resize(n+1,0);
        parents.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++)
        {
            parents[i]=i;
        }

    }
    int findPar(int node)
    {
        if(node==parents[node])
        return parents[node];
        return parents[node]=findPar(parents[node]);
    }
    void unionByrank(int u,int v)
    {
        int mpu=findPar(u);
        int mpv=findPar(v);
        if(mpu==mpv)return;
        if(ranks[mpu]==ranks[mpv])
        {
                  parents[mpv]=mpu;
                  ranks[mpu]+=1;
        }
        else if(ranks[mpu]>ranks[mpv])
        {
                    parents[mpv]=mpu;
        }
        else
        {
                  parents[mpu]=mpv;
        }
    }
    void unionbysize(int u,int v)
    {
        int mpu=findPar(u);
        int mpv=findPar(v);
        if(mpu==mpv)return;
        if(size[mpu]<size[mpv])
        {
            parents[mpu]=mpv;
            size[mpv]+=size[mpu];
        }
        else
        {
             parents[mpv]=mpu;
            size[mpu]+=size[mpv];
        }
    }


};
