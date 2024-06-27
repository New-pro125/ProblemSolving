#include<bits/stdc++.h>
#include<regex>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll Mod= 1e9+7;
const ld EPS=1e-6;
const ll OO=INT_MAX;
typedef __int128_t lll;
#define REP(i,a,b) for(int i=a;i<b;i++)
#define REN(i,a,b) for(int i=a;i>b;i--)
#define _STD_ std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
#define _OPEN_ freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
#define all(v)   (v).begin(),(v).end()
template<typename t>
ostream& operator <<(ostream&out,const vector<t>&vi){
    for( const t&i:vi)
        out<<i<<" ";
    return out;
}
template<typename T>
istream& operator >>(istream&out, vector<T>&vi){
   for(auto&i:vi)
    out>>i;
    return out;
}
template<typename T=int,int Base=1>
struct DSU{
    int Nodes;
    vector<T>parent,Gsize,MinValue,MaxValue,Points;
    vector<vector<T>>Components;
    DSU(int MaxNodes):Nodes(MaxNodes){
        parent=Gsize=MinValue=MaxValue=Points=vector<T>(MaxNodes+1);
        Components=vector<vector<T>>(MaxNodes+1);
        for(int i=Base;i<=MaxNodes;i++)
            parent[i]=i,Gsize[i]=1,MinValue[i]=MaxValue[i]=i,Points[i]=0;
    }
    // O( log(n) )
    T findLeader(int node){
        return parent[node]=(parent[node]==node?node:findLeader(parent[node]));
    }
    bool isSameSet(int u,int v){
        return findLeader(u)==findLeader(v);
    }
    void unionSets(int u,int v){
        Components[u].push_back(v);
        Components[v].push_back(u);
        int leaderU=findLeader(u),leaderV=findLeader(v);
        if(leaderU==leaderV)   return;
        if(Gsize[leaderU]<Gsize[leaderV]) swap(leaderU,leaderV); //Caution: this Condition is pretty important.
        Gsize[leaderU]+=Gsize[leaderV],parent[leaderV]=leaderU;
        MinValue[leaderU]=min(MinValue[leaderU],leaderV);
        MinValue[leaderV]=min(MinValue[leaderV],leaderU);
        MaxValue[leaderU]=max(MaxValue[leaderU],leaderV);
        MaxValue[leaderV]=max(MaxValue[leaderV],leaderU);
    }
    void add(int u, int value){
        Points[u]+=value;
        for(int i=0;i<Components[u].size();i++)
                Points[Components[u][i]]+=value;
    }
    int getSize(int u){
        return Gsize[findLeader(u)];
    }
    int getMinValue(int u){
        return MinValue[findLeader(u)];
    }
    int getMaxValue(int u){
        return MaxValue[findLeader(u)];
    }
};
struct Edge{
    int u,v,d;
    Edge(int U,int V,int D):u(U),v(V),d(D){}
    bool operator > (Edge other)const{
            return this->d > other.d;
    }
};
int doJob(vector<int>&arr,int l,int r){
    int ans=0;
    for(int i=l;i<=r;i++)
        ans+=arr[i];
    return ans;
}
int mergesort(vector<int> & arr,int l,int r){
    int ans=0;
    if(l<r){
        int m=l+(r-l)/2;
        ans+=mergesort(arr,l,m);
        ans+=mergesort(arr,m+1,r);
        ans+=doJob(arr,l,r);
    }
    return ans;
}
void work(){
    int n;
    cin>>n;
    string name;
    cin>>name;
    int sum=-1;
    if(name.find("ABC")!=string::npos)
       sum=name.find("ABC")+1;
    cout<<sum; 

}

int main(){
   _STD_
    #ifndef ONLINE_JUDGE
        _OPEN_
    #endif
    int n=1;
    //cin>>n;
    while(n--)
      work();
}