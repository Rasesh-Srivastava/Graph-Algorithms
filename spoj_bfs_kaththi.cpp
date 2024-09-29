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
const int infi=1e9;
bool cantravel(int x,int y, int r, int c){
    if(x>=0 && x<r && y>=0 && y<c){
        return true;
    }
    else{
        return false;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false),
    cin.tie(NULL),
    cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--)
    {
        int r,c;
        cin>>r>>c;
        char arr[r][c];
        for(int i=0;i<r;i++){
            string s;
            cin>>s;
            for(int j=0;j<c;j++){
                arr[i][j]=s[j];
            }
        }
        int dist[r][c];
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                dist[i][j]=infi;
            }
        }
        bool visited[r][c];
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                visited[i][j]=false;
            }
        }

        dist[0][0]=0;
        visited[0][0]=true;
        deque <pair <int,int>> q;
        q.push_back({0,0});
        while(!q.empty()){
            auto s=q.front();
            q.pop_front();
            int x1=s.first;
            int y1=s.second;
            //travel to x2,y2
            //x2,y2
            if(cantravel(x1+1,y1,r,c) /* && dist[x1+1][y1]>dist[x1][y1] || (visited[x1+1][y1]==false)*/){
                visited[x1+1][y1]=true;
                if(arr[x1+1][y1]!=arr[x1][y1]){
                    if(dist[x1+1][y1]>dist[x1][y1]+1){
                        dist[x1+1][y1]=dist[x1][y1]+1;
                        q.push_back({x1+1,y1});
                    }
                }
                else{
                    if(dist[x1+1][y1]>dist[x1][y1]){
                         dist[x1+1][y1]=dist[x1][y1];
                         q.push_front({x1+1,y1});
                    }
                }
            }
            if(cantravel(x1-1,y1,r,c) /* && dist[x1-1][y1]>dist[x1][y1] || (visited[x1-1][y1]==false)*/){
                visited[x1-1][y1]=true;
                if(arr[x1-1][y1]!=arr[x1][y1]){
                    if(dist[x1-1][y1]>dist[x1][y1]+1){
                        dist[x1-1][y1]=dist[x1][y1]+1;
                        q.push_back({x1-1,y1});
                    }
                }
                else{
                    if(dist[x1-1][y1]>dist[x1][y1]){
                         dist[x1-1][y1]=dist[x1][y1];
                         q.push_front({x1-1,y1});
                    }
                }
            }
            if(cantravel(x1,y1+1,r,c) /* && dist[x1][y1+1]>dist[x1][y1] || (visited[x1][y1+1]==false)*/){
                visited[x1][y1+1]=true;
                if(arr[x1][y1+1]!=arr[x1][y1]){
                    if(dist[x1][y1+1]>dist[x1][y1]+1){
                        dist[x1][y1+1]=dist[x1][y1]+1;
                        q.push_back({x1,y1+1});
                    }
                }
                else{
                    if(dist[x1][y1+1]>dist[x1][y1]){
                         dist[x1][y1+1]=dist[x1][y1];
                         q.push_front({x1,y1+1});
                    }
                }
            }
            if(cantravel(x1,y1-1,r,c) /* && dist[x1][y1-1]>dist[x1][y1] || (visited[x1][y1-1]==false)*/){
                visited[x1][y1-1]=true;
                if(arr[x1][y1-1]!=arr[x1][y1]){
                    if(dist[x1][y1-1]>dist[x1][y1]+1){
                        dist[x1][y1-1]=dist[x1][y1]+1;
                        q.push_back({x1,y1-1});
                    }
                }
                else{
                    if(dist[x1][y1-1]>dist[x1][y1]){
                         dist[x1][y1-1]=dist[x1][y1];
                         q.push_front({x1,y1-1});
                    }
                }
            }
        }
        cout<<dist[r-1][c-1]<<endl;

    }
    
    return 0;
}