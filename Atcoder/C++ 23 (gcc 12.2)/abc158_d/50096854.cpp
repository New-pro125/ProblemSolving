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
    int n;
    cin>>n;
//     stack<int>temp,temp2;
//    for(int i=0;i<n;i++){
//         int c;
//         cin>>c;
//         temp2.push(c);
//         while(!temp.empty()) temp2.push(temp.top()),temp.pop();
//         swap(temp,temp2);
//    }
//    bool flag=false;
//    vector<int> sol;
//    while(!temp2.empty()) sol.push_back(temp2.top()),temp2.pop(),flag=true;
//    while(!temp.empty()&&!flag) sol.push_back(temp.top()),temp.pop();
//     reverse(all(sol));
//     cout<<sol;

    // another solution for using 2 stacks
    /*
        you put the once front and once back 
        if size is odd reverse it 
    */
    deque<int>dq;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(i&1) dq.push_front(x);
        else dq.push_back(x);
    }
    if(n&1) reverse(all(dq));
    for(int i=0;i<n;i++) cout<<dq[i]<<' ';
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