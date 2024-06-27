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
    string temp;
    bool flag=false;
    int i=0;
    int q;
    deque<char>dq;
    cin>>temp;
    cin>>q;
    for(int i=0;i<temp.size();i++) dq.push_back(temp[i]);
    while(i<q){
        int x;
        cin>>x;
        if(x&1){
            flag^=1;
        }
        else{
            int p; char ch;
            cin>>p>>ch;
            if(p&1){
                if(flag)
                    dq.push_back(ch);
                else 
                    dq.push_front(ch);

            }
            else{
                if(flag)
                    dq.push_front(ch);
                else dq.push_back(ch);
            }
        }
        i++;
    }
    if(flag) reverse(all(dq));
    for(int i=0;i<dq.size();i++) cout<<dq[i];
    cout<<'\n';
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