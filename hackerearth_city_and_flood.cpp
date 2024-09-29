//https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-flood-1/
#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
int par[N];
int rnk[N];
int ans=0;
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
    par[p2]=p1;
    rnk[p1]=rnk[p1]+rnk[p2];
    ans++;
    //implemented union by rank
}
int main()
{
    int n,k;
    cin>>n>>k;
    int ans=0;
    make_set(n);
    while(k--){
        int i,j;
        cin>>i>>j;
        union_set(i,j); 
    }
    cout<<n-ans<<endl;
    return 0;
}