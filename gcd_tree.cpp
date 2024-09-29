//gcd
//ans(node) denotes gcd of all nodes of subtree rooted at node
#include <bits/stdc++.h>
using namespace std;
const int N=1000;
vector <int> adj[N];
vector <int> ans(N);
vector <bool> visited(N,false);
vector <int> value(N);
void dfs(int node, int parent){
    ans[node]=value[node];
    // visited[node]=true;
    for(int child : adj[node]){
        if(child==parent) continue;
        dfs(child,node);
        ans[node]=__gcd(ans[node],ans[child]);
    }
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        cin>>value[i];
    }
    dfs(1,-1);
    for(int i=1;i<=n;i++){
        cout<<i<<" "<<ans[i]<<endl;
    }
}