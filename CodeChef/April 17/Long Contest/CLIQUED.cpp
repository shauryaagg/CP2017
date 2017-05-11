#include <stdio.h>
#include <queue>
#include <vector>
#define inf 999999999999999
using namespace std;
 
int t,n,k,m,s,d1,d2;
long long int x,w;
priority_queue<pair<long long int,int>,vector<pair<long long int,int> >,greater<pair<long long int,int> > >pq;
vector<vector<pair<int,long long int> > >ar;
int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%lld%d%d",&n,&k,&x,&m,&s);s--;
        ar.resize(n);
        while(m--){
            scanf("%d%d%lld",&d1,&d2,&w);
            ar[d1-1].push_back(make_pair(d2-1,w));
            ar[d2-1].push_back(make_pair(d1-1,w));
        }
        //DIJKSTRA's ALGORITHM
        vector<long long int>dis(n,inf);
        pq.push(make_pair(0,s));
        dis[s]=0;
        while(!pq.empty()){
            int node=pq.top().second;
            pq.pop();
            for(int i=0;i<ar[node].size();i++){
                if(dis[ar[node][i].first]>ar[node][i].second+dis[node]){
                    dis[ar[node][i].first]=ar[node][i].second+dis[node];
                    pq.push(make_pair(ar[node][i].second+dis[node],ar[node][i].first));
                }
            }
        }
        w=inf;
        for(int i=0;i<k;i++){
            w=min(w,dis[i]);
        }
        for(int i=0;i<k;i++){
            if(dis[i]>w+x){
                dis[i]=w+x;
                pq.push(make_pair(dis[i],i));
            }
        }
        while(!pq.empty()){
            int node=pq.top().second;
            pq.pop();
            for(int i=0;i<ar[node].size();i++){
                if(dis[ar[node][i].first]>ar[node][i].second+dis[node]){
                    dis[ar[node][i].first]=ar[node][i].second+dis[node];
                    pq.push(make_pair(ar[node][i].second+dis[node],ar[node][i].first));
                }
            }
        }
        for(int i=0;i<n;i++){
            printf("%lld ",dis[i]);
        }
        printf("\n");
        ar.clear();
    }
}  