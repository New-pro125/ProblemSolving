#include<bits/stdc++.h>
#include<regex>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll Mod= 1e9+7;
const ld EPS=1e-6;
const ll OO=2e6;
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
ll n;
int k;
vector<ll>stones;
vector<ll>dp;
ll findMin(ll idx=0){
    if(idx==n-1)
        return 0;
    if(idx>n-1)
        return -OO;
    ll &ret=dp[idx];
    if(ret!=INT64_MAX)
        return ret;
        for(int i=1;i<=k;i++)
            if(idx+i<n) 
                ret=min(ret,abs(stones[idx+i]-stones[idx])+findMin(idx+i));
    return ret;
}
void work(){
    cin>>n>>k;
    stones.resize(n);
    dp.assign(n+1,INT64_MAX);
    cin>>stones;
    cout<<findMin()<<endl;
   //cout<<dp;
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