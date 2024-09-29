#include <bits/stdc++.h>
using namespace std;
#define pi 3.14159265358979323846264338327950288419
typedef long long ll;
#define int long long
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
#define setbits(x) __builtin_popcountll(x)
#define scan(a) for(int &i: a) cin>>i
const int N=100009;
vector <pair<int,int> > adj[N]; 
int32_t main()
{
    ios_base::sync_with_stdio(false),
    cin.tie(NULL),
    cout.tie(NULL);
    
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
    }
    int dist[N];
    for(int i=1;i<=n;i++){
        dist[i]=LONG_LONG_MAX;
    }
    dist[1]=0;
    priority_queue <pair<int,int> > pq;
    pq.push({0,1});
    vector <bool> processed(N,false);
    while(!pq.empty()){
        int a=pq.top().second;
        pq.pop();
        if(processed[a]) continue;
        processed[a]=true;
        for(auto &it: adj[a]){
            int child=it.first;
            if(dist[child]>dist[a]+it.second){
                dist[child]=dist[a]+it.second;
                pq.push({-1*dist[child], child});
            }
        }

    }
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    
    return 0;
}