#include <bits/stdc++.h>
using namespace std;
 
int t,n,d,ans;
int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);ans=0;
        for(int i=0;i<n;i++){
            scanf("%d",&d);
            ans=min(i-d,ans)+1;
        }
        printf("%d\n",ans);
    }
} 