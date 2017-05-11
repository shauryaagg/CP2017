#include <bits/stdc++.h>
using namespace std;

int n,d,parent[2000];
vector<pair<int,pair<int,int> > >e;
int find(int x){
    if(parent[x]==x) return x;
    return find(parent[x]);
}
void unite(int a, int b){
    parent[find(a)]=find(b);
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        parent[i]=i;
        for(int j=0;j<n;j++){
            scanf("%d",&d);
            if(i!=j&&i>0&&j>0)
            e.push_back(make_pair(d,make_pair(i-1,j-1)));
        }
    }
    n--;
    sort(e.begin(),e.end());
    int mste=0,mstn=0,mstw=0,a,b,w;
    while(mste<n-1||mstn<e.size()){
        a=e[mstn].second.first;
        b=e[mstn].second.second;
        w=e[mstn].first;
        if(find(a)!=find(b)){
            mstw+=w;
            unite(a,b);
            mste++;
        }
        mstn++;
    }
    printf("%d",mstw);
}