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
const int N=100001;
int32_t main()
{
    ios_base::sync_with_stdio(false),
    cin.tie(NULL),
    cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        vector <int> ans(n+1,1);
        vector <int> deg(n+1,0);
        if(m%2==0){
            cout<<1<<endl;
            for(int i=0;i<n;i++){
                cout<<1<<" ";
            }
            cout<<endl;
            continue;
        }
        int a,b;
        for(int i=0;i<m;i++){
            cin>>a>>b;
            deg[a]++;
            deg[b]++;
        }
        int odd=0;
        for(int i=1;i<=n;i++){
            if(deg[i]%2!=0){
                odd=i;
                break;
            }
        }
        if(odd){
            cout<<2<<endl;
            for(int i=1;i<=n;i++){
                if(i==odd){
                    cout<<2<<" ";
                }
                else{
                    cout<<1<<" ";
                }
            }
        }
        else{
            cout<<3<<endl;
            for(int i=1;i<=n;i++){
                if(i==a){
                    cout<<1<<" ";
                }
                else if(i==b){
                    cout<<2<<" ";
                }
                else{
                    cout<<3<<" ";
                }
            }
        }
        cout<<endl;

    }
    
    return 0;
}