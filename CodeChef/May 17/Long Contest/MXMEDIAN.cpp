#include <bits/stdc++.h>
using namespace std;
 
int t,n,ar[100005];
int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);n<<=1;
        for(int i=0;i<n;i++){
            scanf("%d",&ar[i]);
        }
        sort(ar,ar+n);
        printf("%d\n",ar[3*n>>2]);
        for(int i=n-1;i>=n>>1;i--){
            printf("%d %d ",ar[i],ar[n-1-i]);
        }
        printf("\n");
    }
} 