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
vector<int>freq(9);
vector<int>square;
vector<vector<int>>grid(9,vector<int>(9));
bool sudoku(int row=0,int col=0){
        if(row==9&&col==9)
            return true;
        if(row%3==0)
            square.clear();
        for(int i=0;i<square.size();i++)
            if(grid[row][col]==square[i])
                return false;
        for(int i=0;i<9;i++)
        {    
            if(freq[grid[i][col]-1])
                return false;
            else
                freq[grid[i][col]-1]++;
            if(i>=row&&(i<row+3)&&row%3==0)
                square.push_back(grid[i][col]);
        }
            freq.assign(9,0);
        for(int j=0;j<9;j++)
        {    
            if(freq[grid[row][j]-1])
                return false;
            else
                freq[grid[row][j]-1]++;
            if(j>=col&&(j<col+3)&&col%3==0)
                square.push_back(grid[row][j]);
        }
        freq.assign(9,0);
        bool ans=true;
        ans&=sudoku(row+1,col+1);
        return ans;
}
void work(){
    ll n=9;
    for(int i=0;i<9;i++)
        cin>>grid[i];
    cout<<(sudoku()?"Yes":"No");
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
