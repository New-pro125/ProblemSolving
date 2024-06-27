#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<regex>
#include<cmath>
#include<iomanip>
#include<queue>
#include<stack>
//#include<bits/stdc++.h>
//#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll Mod= 1e9+7;
const ld EPS=1e-6;
#define REP(i,a,b) for(int i=a;i<b;i++)
#define REN(i,a,b) for(int i=a;i>b;i--)
#define _STD_ std::ios::sync_with_stdio(false);std::cin.tie(nullptr);std::cout.tie(nullptr);
#define _OPEN_ freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
#define all(v)   (v.begin()),(v.end())
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
void work(){
    string temp,rotated;
    cin>>temp>>rotated;
    deque<char>dq;
    for(size_t i=0;i<temp.size();i++) dq.push_back(temp[i]);
    if(temp==rotated) return void(cout<<"Yes\n");
    for(size_t i=0;i<temp.size();i++){
        char t=dq.back();
        dq.push_front(t);
        dq.pop_back();
        string now(all(dq));
        if(now==rotated) return void(cout<<"Yes\n");
    }
    cout<<"No\n";
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