#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mod 1000000007
#define endl '\n' 
#define setbits   __builtin_popcountll
#define msort(v)  sort((v).begin(),(v).end())
#define all(c)  (c).begin(), (c).end()
#define fill(container, value)  memset((container), (value), sizeof(container))
#define test ll t; cin >> t; while (t--)
#define fast_IO    ios_base::sync_with_stdio(false);    cin.tie(NULL);
void dfs(int node,int par,vector<bool> &vis,vector<int> &tim,vector<int> &low,int &timer,vector<int> adj[]){
      vis[node] = true;
      timer++;
      tim[node] = timer;
      low[node] = timer;
      for(auto it:adj[node]){
          if(it!=par) {
              if(!vis[it]){
                  dfs(it,node,vis,tim,low,timer,adj);
                  low[node]=min(low[node],low[it]);
                  if(low[it]>tim[node]){
                      cout<<node<<" "<<it<<endl;
                  }
              }
              else{
                low[node]=min(low[node],tim[it]);
              }
          }
      } 
}
void solve(){
 ll n,m,u,v;
 cin >> n >> m;
 vector<int>adj[n+1];
 vector<bool>vis(n,false);
 vector<int>low(n,-1);
 vector<int>tim(n,-1);
 for(int i=0;i<m;i++){
     cin>>u>>v;
     adj[u].push_back(v);
     adj[v].push_back(u);
 }
 int timer=0;
 for(int i=0;i<n;i++){
     if(!vis[i]){
         dfs(i,-1,vis,tim,low,timer,adj);
     }
 }

}
int main(){
fast_IO;
//test
solve();
return 0;
}