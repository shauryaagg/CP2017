//CRITINTS (AP) => O(V+E)
#include <iostream>
#include <stdio.h>
#include <vector>
#include <list>
#include <map>
#include <cstring>
#include <algorithm>
#include <iomanip>
#define inf -1
using namespace std;

int n,m,d1,d2,tim=0,ans=0,low[305],disc[305],parent[305];
vector<vector<int> >ar;
bool vis[305],ap[305];
void dfs(int u){
    vis[u]=true;
    low[u]=disc[u]=++tim;
    int child=0;
    for(int i=0;i<ar[u].size();i++){
        if(!vis[ar[u][i]]){
            child++;
            parent[ar[u][i]]=u;
            dfs(ar[u][i]);
            low[u]=min(low[u],disc[ar[u][i]]);
            if(parent[u]!=inf&&low[ar[u][i]]>=disc[u]){
                ap[u]=true;
            }
            else if(parent[u]==inf&&child>1){
                ap[u]=true;
            }
        }
        else if(ar[u][i]!=parent[u]){
            low[u]=min(low[u],disc[ar[u][i]]);
        }
    }
}
int main() {
    scanf("%d%d",&n,&m);
    ar.resize(n);
    for(int i=0;i<m;i++){
        scanf("%d%d",&d1,&d2);
        ar[d1-1].push_back(d2-1);
        ar[d2-1].push_back(d1-1);
    }
    memset(parent,-1,n+1);
    memset(low,0,n+1);
    memset(vis,false,n+1);
    memset(ap,false,n+1);
    dfs(0);
    for(int i=0;i<n;i++){
        if(ap[i]){
            ans++;
        }
    }
    printf("%d\n",ans);
    for(int i=0;i<n;i++){
        if(ap[i]){
            printf("%d\n",i+1);
        }
    }
}