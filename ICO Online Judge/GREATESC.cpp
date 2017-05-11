//GREATESC
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int n,m,d1,d2,s,t,b,depth[4000];
vector<vector<int> >ar;
queue<int>q;
int bfs(){
    q.push(s);
    depth[s]=0;
    while(!q.empty()){
        b=q.front();
        q.pop();
        if(b==t)
        return depth[b];
        for(int i=0;i<ar[b].size();i++){
            if(depth[ar[b][i]]==-1){
                depth[ar[b][i]]=depth[b]+1;
                q.push(ar[b][i]);
            }
        }
    }
    return 0;
}
int main() {
    scanf("%d%d",&n,&m);
    ar.resize(n);
    for(int i=0;i<m;i++){
        scanf("%d%d",&d1,&d2);
        ar[d1-1].push_back(d2-1);
        ar[d2-1].push_back(d1-1);
    }
    scanf("%d%d",&s,&t);
    s--;t--;
    for(int i=0;i<=n;i++)depth[i]=-1;
    if(s>=0&&t>=0&&s<n&&t<n)
    printf("%d",bfs());
    else
    printf("0");
}