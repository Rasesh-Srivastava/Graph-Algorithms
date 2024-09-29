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
#define setbits(x) __builtin_popcountll(x)
#define scan(a) for(int &i: a) cin>>i
 
int32_t main()
{
    ios_base::sync_with_stdio(false),
    cin.tie(NULL),
    cout.tie(NULL);
    int t=0;
    while(++t){
        int n;
        cin>>n;
        if(n==0){
            return 0;
        }
        map <string,int> m;
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            m[s]=i+1;
        }
        int e;
        cin>>e;
        vector <pair<int,double> > adj[31];
        vector <pair <int, pair<int, double>>> edges;
        for(int i=0; i<e;i++){
            string s1,s2;
            double r;
            cin>>s1>>r>>s2;
            adj[m[s1]].push_back({m[s2],r});
            edges.push_back({m[s1],{m[s2],r}});
        }
        vector <double> val(n+1,-1);
        val[1]=1.0;
        for(int i=1;i<=n-1;i++){
            for(auto &x: edges){
                int u=x.first;
                int v=x.second.first;
                double w=x.second.second;
                val[v]=max(val[v], val[u]*w);
            }
        }
        bool found=false;
        for(auto &x: edges){
            int u=x.first;
            int v=x.second.first;
            double w=x.second.second;
            if(val[v]<val[u]*w){
                cout<<"Case "<<t<<": Yes"<<endl;
                found=true;
                break;
            }
        }
        if(found) continue;
        cout<<"Case "<<t<<": No"<<endl;
        string discard;
        getline(cin,discard);
    }
    
    
    
    return 0;
}