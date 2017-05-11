#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
 
int t,n,k,d,d1,d2,ans=0;
bool vis[100005],f;
vector<vector<int> >ar;
int main() {
   scanf("%d",&t);
   while(t--){
       scanf("%d%d",&n,&k);
       ar.resize(n);
       f=false;
       for(int i=0;i<=k+1;i++){
           vis[i]=false;
       }
       ans=0;
       for(int i=0;i<n;i++){
            scanf("%d",&d1);
            int d=0;
            for(int j=0;j<d1;j++){
                scanf("%d",&d2);
                ar[i].push_back(d2);
                if(!vis[d2]){
                    vis[d2]=true;
                    ans++;
                }
                else
                d++;
            }
            if(d==d1){
                f=true;
            }
       }
       if(ans<k){
           printf("sad\n");
       }
       else if(f){
           printf("some\n");
       }
       else{
            for(int i=0;i<=k+1;i++){
                vis[i]=false;
            }
            for(int i=n-1;i>=0;i--){
                int d=0;
                for(int j=0;j<ar[i].size();j++){
                    if(!vis[ar[i][j]]){
                        vis[ar[i][j]]=true;
                    }
                    else
                    d++;
                }
                if(d==ar[i].size()){
                    f=true;
                }
            }
            if(f){
                printf("some\n");
            }
            else{
                printf("all\n");
            }
        }
        ar.clear();
   }
} 