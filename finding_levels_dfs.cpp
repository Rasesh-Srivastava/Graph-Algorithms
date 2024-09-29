#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define pii pair<int,int>
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)
#define vi vector <int>
#define vll vector <long long>
const int N=1000;
vector<int> adj[N]; // graph represented as an adjacency list
int n; // number of vertices
int m;//number of edges
vector<bool> visited(N+1,false);
vector <int> dist(N);
void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (visited[u]) continue;
        dist[u]=dist[v]+1;
        dfs(u);
    }
}//o(n+m)
 
int32_t main()
{
    ios_base::sync_with_stdio(false),
    cin.tie(NULL),
    cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
    dist[0]=0;
    for(int i=0;i<n;i++){
        cout<<i<<" "<<dist[i]<<endl;
    }
    
    return 0;
}