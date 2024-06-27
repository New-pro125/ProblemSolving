#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
  ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  ll n;
  cin>>n;
  vector<ll>dist(n),dp(n+1,0);
  for(int i=0;i<n;i++) cin>>dist[i];
  for(int i=0;i<=n;i++){
    if(i-1>=0)
        dp[i]=min((ll)INT64_MAX,dp[i-1]+abs(dist[i]-dist[i-1]));  
    if(i-2>=0)
        dp[i]=min(dp[i],dp[i-2]+abs(dist[i]-dist[i-2]));  
    //dp[i]=min(dp[i],abs(dp[i]-dp[i-2]));  
  }
  cout<<dp[n-1]<<'\n';
  return 0;
}
