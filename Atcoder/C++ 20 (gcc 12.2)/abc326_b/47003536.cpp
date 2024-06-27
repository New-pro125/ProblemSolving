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
bool good(int n){
    int ones=n%10;
    n/=10;
    int pro=1;
    while(n){
        pro*=n%10;
        n/=10;
    }
    return pro==ones;
}
void work(){ 
   int n;
   cin>>n;
   while(!good(n)) n++;
   cout<<n;
}
int main(){
   _STD_
    #ifndef ONLINE_JUDGE
        _OPEN_
    #endif
    ll n=1;
    //cin>>n;
    // while(n--)
      work();
}
