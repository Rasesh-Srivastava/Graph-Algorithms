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
int n,m;
int visited[1001][1001];
int ans[1001][1001];
queue <pair<int,int> > q;
int a[]={0,0,1,-1};
int b[]={1,-1,0,0};
char arr[1001][1001];
int temp;
bool cantravel(int x2, int y2){
    if(x2>=0 && x2<n && y2>=0 && y2<m && arr[x2][y2]=='.' &&visited[x2][y2]==0){
        return true;
    }
    return false;
}
void bfs(int x, int y){
    visited[x][y]=1;
    q.push({x,y});
    ans[x][y]=temp;
    while(!q.empty()){
        int x1=q.front().first;
        int y1=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int x2=x1+a[i];
            int y2=y1+b[i];
            if(cantravel(x2,y2)){
                q.push({x2,y2});
                visited[x2][y2]=1;
                ans[x2][y2]=temp;
            }
        }
    }
    temp++;
}

int32_t main()
{
    ios_base::sync_with_stdio(false),
    cin.tie(NULL),
    cout.tie(NULL);
    memset(visited, 0, sizeof visited);
    memset(ans, -1, sizeof ans);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]=='.' && visited[i][j]==0){
                count++;
                bfs(i,j);
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<ans[i][j]<<" ";  
    //     }
    //     cout<<endl;
    // }
    cout<<count<<endl;
    return 0;
}