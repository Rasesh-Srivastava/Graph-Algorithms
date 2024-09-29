//https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-soldiers/
#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
int par[N];
void make_set(int n){
    //make set containing all elements from 1 to n
    for(int i=1;i<=n;i++){
        par[i]=i;
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
    par[p1]=p2;
    //implemented union by rank
}
int main()
{
    int n,q;
    cin>>n>>q;
    make_set(n);
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            int a,b;
            cin>>a>>b;
            union_set(a,b);
        }
        else if(op==2){
            int a;
            cin>>a;
            int b=find_set(a);
            par[b]=a;
            par[a]=a;
        }
        else{
            int a;
            cin>>a;
            cout<<find_set(a)<<endl;
        }
    }
    return 0;
}