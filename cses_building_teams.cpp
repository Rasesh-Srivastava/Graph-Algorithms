#include <bits/stdc++.h>
using namespace std;
#define pi 3.14159265358979323846264338327950288419
typedef long long ll;
#define pb push_back
#define pii pair<int,int>
#define mod 1000000007
#define rep(i,n) for(int i=0;i<n;i++)
#define vi vector <int>
#define vll vector <long long>
#define get_max(a) *max_element(a.begin(),a.end())
#define get_min(a) *min_element(a.begin(),a.end())
#define get_sum(a) accumulate(a.begin(),a.end(),0LL)
#define all(a) a.begin(),a.end()
#define int long long
const int N=100010;
vector <bool> visited(N,false);
vector <int> dist(N);
vector <int> adj[N];
int d;
int maxi=-1;
bool impossible=false;
void dfs(int v){
    visited[v]=true;
    d++;
    for(int child : adj[v]){
        if(visited[child]){
            if(dist[child]%2==dist[v]%2){
                impossible=true;
                return ;
            }
            else{
                continue;
            }
        }
        dist[child]=dist[v]+1;
        maxi=max(maxi,dist[child]);
        dfs(child);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false),
    cin.tie(NULL),
    cout.tie(NULL);
    
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int temp;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dist[i]=maxi+1;
            dfs(i);
            if(impossible){
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }
    vector <int> a1,a2;
    for(int i=1;i<=n;i++){
        if(dist[i]%2==0){
            // cout<<1<<" ";
            a1.push_back(i);
        }
        else{
            // cout<<2<<" ";
            a2.push_back(i);
        }
    }
    if(a1.size()==0 || a2.size()==0 || impossible){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
            if(dist[i]%2==0){
                cout<<1<<" ";
            }
            else{
                cout<<2<<" ";
            }
        }
    return 0;
}