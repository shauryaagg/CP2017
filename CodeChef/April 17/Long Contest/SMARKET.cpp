#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
 
int t,n,q,l,r,k,ar[1000005],ord[1000005],next[1000005],ans;
int main() {
    scanf("%d",&t);
    while(t--){vector<vector<int> >order(1000005);
        scanf("%d%d",&n,&q);
        ord[0]=0;
        int last=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&ar[i]);
            if(ar[i-1]==ar[i]){
                ord[i]=ord[i-1]+1;
            }
            else{
                next[last]=i-1;
                ord[i]=1;
                last=i;
            }
            order[ord[i]].push_back(i);
        }
        next[last]=n;
        while(q--){
            scanf("%d%d%d",&l,&r,&k);
            ans=0;
            if(next[l-ord[l]+1]-l+1>=k){
                ans++;
            }
            l=next[l-ord[l]+1]+1;
            if(l+k-1<=r&&!binary_search(order[k].begin(),order[k].end(),r))
            ans+=lower_bound(order[k].begin(),order[k].end(),r)-lower_bound(order[k].begin(),order[k].end(),l);
            else if(l+k-1<=r)
            ans+=lower_bound(order[k].begin(),order[k].end(),r)-lower_bound(order[k].begin(),order[k].end(),l)+1;
            printf("%d\n",ans);
        }
    }
} 