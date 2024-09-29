#include <bits/stdc++.h>
using namespace std;
const int N=100009;
stack <int> ts;
vector <int> adj[N];
bool vis[N];
void dfs(int v){
    vis[v]=true;
    for(auto &child: adj[v]){
        if(!vis[child]) dfs(child);
    }
    ts.push(v);
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    dfs(1);
    if(vis[n]==false){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    vector <int> topo;
    while(!ts.empty()){
        int topelement=ts.top();
        ts.pop();
        topo.push_back(topelement);
    }
    int dist[N];
    int parent[N];
    for(int i=1;i<=n;i++) {
        dist[i]=-1;
        parent[i]=-1;
    }
    dist[1]=1;

    for(int &u: topo){
        for(int &v: adj[u]){
            if(dist[v]<dist[u]+1){
                dist[v]=dist[u]+1;
                parent[v]=u;
            }
        }
    }
    int i=n;
    vector <int> path;
    while(true){
        path.push_back(i);
        if(i==1) break;
        i=parent[i];
    }
    cout<<path.size()<<endl;
    reverse(path.begin(),path.end());
    for(int p: path){
        cout<<p<<" ";
    }

}