//https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-fireman-vincent/
//Disjoint Set Union
//Data structure used for performing union of disjoint sets efficiently
#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
int par[N];
int rnk[N];
void make_set(int n){
    //make set containing all elements from 1 to n
    for(int i=1;i<=n;i++){
        par[i]=i;
        rnk[i]=1;
    }
}
int find_set(int x){
    //return representative of set containing x
    if(x==par[x]) return x;
    return par[x]=find_set(par[x]);//path compression
}
void union_set(int x, int y){
    //union sets containing elements x and element y
    if(find_set(x)==find_set(y)){
        //already in same set
        return;
    }
    int p1=find_set(x);
    int p2=find_set(y);
    if(rnk[p1]>=rnk[p2]){
        par[p2]=p1;
        rnk[p1]=rnk[p1]+rnk[p2];
    }
    else{
        par[p1]=p2;
        rnk[p2]=rnk[p2]+rnk[p1];
    }
    //implemented union by rank
}
int main()
{
    int n;
    cin>>n;
    make_set(n);
    int e[n+1];
    for(int i=1;i<=n;i++) cin>>e[i];
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        union_set(a,b);
    }
    map <int, vector <int> > m;
    for(int i=1;i<=n;i++){
        int p=find_set(i);
        m[p].push_back(e[i]);
    }
    int ans=1;
    for(auto &v: m){
        int mini=*min_element(v.second.begin(),v.second.end());
        int temp=0;
        for(auto &u: v.second){
            if(u==mini){
                temp++;
            }
        }
        ans=(ans*temp)%(1000000007);
        ans=ans%(1000000007);
    }
    cout<<ans<<endl;
    return 0;
}