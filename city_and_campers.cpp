//https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-campers/
#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,q;
int par[N];
int rnk[N];
int smol=1;
int large=1;
multiset <int> ms;
void make_set(int n){
    //make set containing all elements from 1 to n
    for(int i=1;i<=n;i++){
        par[i]=i;
        rnk[i]=1;
        ms.insert(1);
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
    ms.erase(ms.find(rnk[p1]));
    ms.erase(ms.find(rnk[p2]));
    if(rnk[p1]>=rnk[p2]){

        par[p2]=p1;
        rnk[p1]=rnk[p1]+rnk[p2];
        ms.insert(rnk[p1]);
    }
    else{
        par[p1]=p2;
        rnk[p2]=rnk[p2]+rnk[p1];
        ms.insert(rnk[p2]);
    }
    //implemented union by rank
}
int findmin(int n){
    int ans=INT_MAX;
    for(int i=1;i<=n;i++){
        ans=min(ans,rnk[find_set(i)]);
    }
}
int main()
{
    cin>>n>>q;
    make_set(n);
    while(q--){
        int a,b;
        cin>>a>>b;
        union_set(a,b);
        auto it1=ms.begin();
        auto it2=prev(ms.end());
        cout<<*it2-*it1<<endl;
    }
    return 0;
}