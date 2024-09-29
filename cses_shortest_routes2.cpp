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
#define infi 100000000000000000
int adj[501][501];
int32_t main()
{
    ios_base::sync_with_stdio(false),
    cin.tie(NULL),
    cout.tie(NULL);
    
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        if(adj[a][b]!=0){
            adj[a][b]=min(adj[a][b],w);
            adj[b][a]=min(adj[a][b],w);
        }
        else{
            adj[a][b]=w;
            adj[b][a]=w;
        }
        
    }
    int dist[n+1][n+1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                dist[i][j]=0;
            }
            else if(adj[i][j]!=0){
                dist[i][j]=adj[i][j];
            }
            else{
                dist[i][j]=infi;
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    while(q--){
        int x,y;
        cin>>x>>y;
        if(dist[x][y]==infi){
            cout<<-1<<endl;
        }
        else{
            cout<<dist[x][y]<<endl;
        }
    }
    
    return 0;
}