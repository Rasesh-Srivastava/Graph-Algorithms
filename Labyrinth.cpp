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
const int N=1001;
int n,m;
char arr[N][N];
queue <pair <int, int> >q;
int a[]={0,0,1,-1};
int b[]={1,-1,0,0};
int visited[1001][1001];
int dist[1001][1001];
char parent[1001][1001];
bool cantravel(int x2, int y2){
    if(x2>=0 && x2<n && y2>=0 && y2<m && arr[x2][y2]!='#'  &&visited[x2][y2]==0){
        return true;
    }
    return false;
}
bool cantravel1(int x2, int y2){
    if(x2>=0 && x2<n && y2>=0 && y2<m && arr[x2][y2]!='#'  &&visited[x2][y2]==1){
        return true;
    }
    return false;
}
void bfs(int x, int y){
    visited[x][y]=1;
    dist[x][y]=0;
    q.push({x,y});
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
                if(i==0){
                    parent[x2][y2]='L';
                }
                else if(i==1){
                    parent[x2][y2]='R';
                }
                else if(i==2){
                    parent[x2][y2]='U';
                }
                else{
                    parent[x2][y2]='D';
                }
                dist[x2][y2]=dist[x1][y1]+1;
            }
            if(cantravel1(x2,y2)){
                if(dist[x2][y2]>dist[x1][y1]+1){
                    dist[x2][y2]=dist[x1][y1]+1;
                    q.push({x2,y2});
                }
            }

        }
    }
}
string path;
void trace(int x, int y){
    if(parent[x][y]=='x') return;
    if(parent[x][y]=='L') {
        path.push_back('R');
        trace(x,y-1);
    }
    if(parent[x][y]=='R') {
        path.push_back('L');
        trace(x,y+1);
    }
    if(parent[x][y]=='U') {
        path.push_back('D');
        trace(x-1,y);
    }
    if(parent[x][y]=='D') {
        path.push_back('U');
        trace(x+1,y);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false),
    cin.tie(NULL),
    cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dist[i][j]=1e9;
            parent[i][j]='x';
        }
    }
    int startx, starty, endx, endy;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            if(arr[i][j]=='A'){
                startx=i;
                starty=j;
            }
            if(arr[i][j]=='B'){
                endx=i;
                endy=j;
            }
        }
    }
    bfs(startx,starty);
    if(!visited[endx][endy]){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        cout<<dist[endx][endy]<<endl;
        trace(endx,endy);
        reverse(all(path));
        cout<<path<<endl;
        // cout<<parent[endx][endy]<<endl;
    }
    return 0;
}