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
stack<int>s;
void dfs(int node,vector<int>adj[],vector<bool>&vis){
    vis[node]=true;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis);
        }
    }
    s.push(node);
}
void rdfs(int node,vector<int>rev[],vector<bool>&rvis){
    rvis[node]=true;
    for(auto it:rev[node]){
        if(!rvis[it]){
            rdfs(it,rev,rvis);
        }
    }
}
void solve(){
  ll n,m,u,v;
 cin >> n >> m ;

 vector<int>adj[n+1];
 vector<int>rev[n+1];
 vector<bool>vis(n,false);
 vector<bool>rvis(n,false);
 
  for(int i=0;i<m;i++){
     cin>>u>>v;
     adj[u].push_back(v);
     rev[v].push_back(u);
 }
 for(int i=0;i<n;i++){
    if(!vis[i]){
        dfs(i,adj,vis);
    }
 }

 while(!s.empty()) {
    int top=s.top();
    s.pop();
    if(!rvis[top]){
        rdfs(top,rev,rvis);
        cout<<top<<endl;
    }
 }
}
int main(){
fast_IO;
//test
solve();
return 0;
}