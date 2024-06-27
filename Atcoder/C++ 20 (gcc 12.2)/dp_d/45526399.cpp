#include<bits/stdc++.h>
#include<regex>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll Mod= 1e9+7;
const ld EPS=1e-6;
const ll OO=INT64_MAX;
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
 
// void work(){
// int n;
// cin>>n;
// vector<int>ans(n);
//     cin>>ans;
//     vector<int>result(n);
//     sort(ans.begin(),ans.end(),greater<>());
//     int m=n;
//     for(int i=0;i<n;i++){
//         result[i]=m;
//     m--;   
//     }
//     cout<<result;
//     cout<<endl;
// }
int n,w;
vector<int>values;
vector<int>weights;
vector<vector<ll>>dp;
ll findMax(int idx,int we){
    if(idx==n||we<0)    return (we>=0)?0:-OO;
    ll &ans=dp[idx][we];
    if(~ans)return ans;
    ans=max(ans,findMax(idx+1,we));
    ans=max(ans,values[idx]+findMax(idx+1,we-weights[idx]));
    return ans;
}
void work(){
    cin>>n>>w;
    values.resize(n),weights.resize(n);
    dp.assign(n+1,vector<ll>(w+1,-1));
    for(int i=0;i<n;i++)
        cin>>weights[i]>>values[i];
    cout<<findMax(0,w);
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