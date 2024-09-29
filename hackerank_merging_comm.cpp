// https://www.hackerrank.com/challenges/merging-communities/problem
#include <bits/stdc++.h>
using namespace std;
const int N=100001;
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
    int n,q;
    cin>>n>>q;
    make_set(n);
    while(q--){
        char c;
        cin>>c;
        if(c=='M'){
            int a,b;
            cin>>a>>b;
            union_set(a,b);
        }
        else{
            int a;
            cin>>a;
            int p=find_set(a);
            // cout<<p<<endl;
            cout<<rnk[p]<<endl;
        }
    }

    return 0;
}