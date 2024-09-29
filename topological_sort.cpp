//applicable only in a directed acyclic graph
//if there is a path from a to b then a appears before b.
//this type of ordering is topological sort
#include <bits/stdc++.h>
using namespace std;
const int N=100010;
vector <bool> visited(N,false);
vector <int> adj[N];
vector <int> state(N,0);
//state=0//not processed yet
//state=1 currently being processed
//state=2 processed
bool cycle_present=false;
vector <int> ans;
void dfs(int node){
    // state[node]==1;
    for(int child : adj[node]){
        if(state[child]==0){
            state[child]=1;
            dfs(child);
        }
        
        else if(state[child]==1){
            cycle_present=true;
            return;
        }
    }
    state[node]=2;
    ans.push_back(node);
}
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        if(state[i]==0){
            state[i]=1;
            dfs(i);
            if(cycle_present){
                cout<<"IMPOSSIBLE"<<endl;
                break;
            } 
        }
    }
    
    if(!cycle_present){
        reverse(ans.begin(),ans.end());
        for(int node : ans){
            cout<<node<<" ";
        }
    }
}
