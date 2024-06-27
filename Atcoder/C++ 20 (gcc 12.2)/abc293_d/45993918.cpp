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
    vector<T>parent,Gsize;
    DSU(int MaxNodes){
        parent=Gsize=vector<T>(MaxNodes+5);
        for(int i=Base;i<=MaxNodes;i++)
            parent[i]=i,Gsize[i]=1;
    }
    // O( log(n) )
    T findLeader(int node){
        return parent[node]=(parent[node]==node?node:findLeader(parent[node]));
    }
    bool isSameSet(int u,int v){
        return findLeader(u)==findLeader(v);
    }
    void unionSets(int u,int v){
        int leaderU=findLeader(u),leaderV=findLeader(v);
        if(leaderU==leaderV)   return;
            if(Gsize[leaderU]<Gsize[leaderV]) swap(leaderU,leaderV); //Caution: this Condition is pretty important.
            Gsize[leaderU]+=Gsize[leaderV],parent[leaderV]=leaderU;
    }
    int getSize(int u){
        return Gsize[findLeader(u)];
    }
};
void work(){
    int n,m;
    cin>>n>>m;
    DSU<int>dsu(n);
    vector<pair<int,int>>edges(m);
    map<int,int>cntEdges;
    for(auto & [u,v]:edges){
        char c;
        cin>>u>>c>>v>>c;
        dsu.unionSets(u,v);
    }
    for(int i=1;i<=n;i++)
        cntEdges[dsu.findLeader(i)]=0;
    int not_cycle=0,cycle=0;
    for(auto & [u,v]:edges){
        int leader=dsu.findLeader(u);
        cntEdges[leader]++;
    }
    for(auto & [leader,cnt]:cntEdges){
        if(cnt!=dsu.getSize(leader))
            not_cycle++;
        else 
            cycle++;
    }
    cout<<cycle<<" "<<not_cycle<<"\n";
}

int main(){
   _STD_
    #ifndef ONLINE_JUDGE
        _OPEN_
    #endif
    int n=1;
   // cin>>n;
    while(n--)
      work();
}