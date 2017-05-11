#include <stdio.h>
#include <vector>
using namespace std;
 
int n,m,k,d1,d2,out[3005],ans=0;
vector<vector<int> >ar;
vector<int>q;
bool del[3005],inQ[3005];
int main() {
        scanf("%d%d%d",&n, &m, &k);
        ar.resize(n);
        for(int i=0;i<m;i++){
            scanf("%d%d",&d1,&d2);
            ar[d1-1].push_back(d2-1);
            ar[d2-1].push_back(d1-1);
            out[d1-1]++;
            out[d2-1]++;
        }
        for(int i=0;i<n;i++){
            if(out[i]<k){
              q.push_back(i); 
              inQ[i]=true;
            }
        }
        while(!q.empty()){
            int i=q.back();
            q.pop_back();
            inQ[i]=false;
            if(out[i]<k&&!del[i]){
                del[i]=true;
                ans++;
                out[i]=1000000;
                for(int j=0;j<ar[i].size();j++){
                    out[ar[i][j]]--;
                    if(out[ar[i][j]]<k&&!inQ[ar[i][j]]&&!del[ar[i][j]]){
                        inQ[ar[i][j]]=true;
                        q.push_back(ar[i][j]);
                    }
                }
            }
        }
        ans=n-ans;
        if(ans){
            printf("YES\n%d",ans);
        }
        else{
            printf("NO");
        }
        return 0;
}