//c++ program to check if the graph is bipartite
//team 0, team 1
#include <bits/stdc++.h>
using namespace std;
const int N=1000;
vector <bool> visited(N);
vector <int> adj[N];
vector <int> team(N);// team[x]=0/1
bool dfs(int node, int currteam){
    visited[node]=true;
    team[node]=currteam;
    for(int child : adj[node]){
        if(visited[child]){
            if(team[child]==team[node]){
                return false;
            }
        }
        else{
            bool temp=dfs(child, ~currteam);
            if(temp==false) return false;
        }
    }
    return true;
}