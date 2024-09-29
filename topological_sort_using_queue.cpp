//applicable only in a directed acyclic graph
//if there is a path from a to b then a appears before b.
//this type of ordering is topological sort
#include <bits/stdc++.h>
using namespace std;
const int N=100010;
vector <int> adj[N];
vector <int> ts;
vector <int> state(N,0);
vector <bool> visited(N,false);
int n,e;
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
int main()
{
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
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
}
