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
vector <string> color(N, "white");
//white-> not visited
//gray-> currently processing
//black-> visited and completed

void dfs(int v) {
    // visited[v] = true;
    color[v]="gray";
    for (int u : adj[v]) {
        if(color[u]=="white"){
            cout<<"parent "<<v<<" child "<<u<<" parent color "<<color[v]<<" child color "<<color[u]<<endl;
            dfs(u);
        }
    }
    color[v]="black";
    cout<<" parent "<<v<<" completed parent color "<<color[v]<<endl;

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
    dfs(1);
    
    return 0;
}