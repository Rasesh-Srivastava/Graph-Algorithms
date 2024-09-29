// Program to find shortest path in a directed acyclic graph from a given source vertex
#include <bits/stdc++.h>
using namespace std;
const int N=100010;
#define inf 1e18;
vector <int> adj[N];
vector <pair<int,int>> adj1[N];
vector <int> ts;
vector <int> state(N,0);
vector <bool> visited(N,false);
int n,e;// number of nodes and number of edges
bool cycle_present=false;
void topological_sort(){
    vector <int> indegree(N,0);
    queue <int> q;
    for(int i=1;i<=n;i++){
        for(auto &child: adj[i]){
            indegree[child]++;
        }
    }
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int f=q.front();
        q.pop();
        ts.push_back(f);
        for(auto &child: adj[f]){
            indegree[child]--;
            if(indegree[child]==0){
                q.push(child);
            }
        }
    }
    
}
void cycle_check(int v){
    for(int &child: adj[v]){
        if(state[child]==1){
            cycle_present=true;
            return;
        }
        else if(state[child]==0){
            state[child]=1;
            cycle_check(child);
        }
    }
    state[v]=2;
    return;
}
int dist[N];
int parent[N];
void shortest_path_DAG(int source){
    for(int i=1;i<=n;i++){
        dist[i]=inf;
        parent[i]=-1;
    }
    dist[source]=0;
    for(auto &v: ts){
        for(auto &u : adj1[v]){
            int child=u.first;
            int weight=u.second;
            // dist[child]=min(dist[child],dist[v]+weight);
            if(dist[child]>dist[v]+weight){
                dist[child]=dist[v]+weight;
                parent[child]=v;
            }
        }
    }
}
int main()
{
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back(b);
        adj1[a].push_back({b,w});
    }
    
    for(int i=1;i<=n;i++){
        if(state[i]==0){
            state[i]=1;
            cycle_check(i);
        }
    }
    if(cycle_present){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    topological_sort();
    for(auto x: ts){
        cout<<x<<" ";
    }
    // all elements in vector ts are sorted in a topological order

}
