#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll Mod= 1e9+7;
const ld EPS=1e-6;
const ll OO=INT_MAX;
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
struct Edge{
    int u,v,d;
    Edge(int U,int V,int D):u(U),v(V),d(D){}
    bool operator > (Edge other)const{
            return this->d > other.d;
    }
};
// string hashing(int n){
//     string hashed;
//     while(n){
//         hashed=hashed +(char)('a'+n%26) ;
//         n/=26;
//     }
//     return hashed;
// }

// void work(){ 
//    ll n,m,sum=0;
//    cin>>n>>m;
//    vector<ll>ans(n),pre(n);
//    cin>>ans;
//    sort(all(ans));
//     pre[0]=0;
//     for(ll i=1;i<n;i++)
//         pre[i]+=(ans[i]-ans[0]);
//     for(ll i=0;i<n;i++)
//         if(m<=pre[i])
//             return void(cout<<i);
//         //cout<<sum;
// }

void work(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n-1;i++){
        if((s[i]=='a'&&s[i+1]=='b')||(s[i]=='b'&&s[i+1]=='a'))
            return void(cout<<"Yes\n");
    }
    cout<<"No\n";
}
int main(){
   _STD_
    #ifndef ONLINE_JUDGE
        _OPEN_
    #endif
    ll n=1;
   // cin>>n;
     while(n--)
      work();
}
