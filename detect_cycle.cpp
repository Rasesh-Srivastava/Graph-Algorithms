//detect cycle in a undirected graph
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

bool cycle_exist(int v, int parent) {
    visited[v] = true;
    for (int u : adj[v]) {
        if(!visited[u]){
            //node u not visited yet
            if(cycle_exist(u,v)){
                return true;
            }
        }
        else{
            //node u already visited
            if(u!=parent){
                return true;
            }
        }
    }
    return false;
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
    int f=1;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(cycle_exist(i,-1)){
                cout<<"cycle exists"<<endl;
                f=0;
                break;
            }
        }
    }
    if(f==1){
        cout<<"cycle doesn't exist"<<endl;
    }
    
    return 0;
}