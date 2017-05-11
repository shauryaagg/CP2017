//EQGIFTS
#include <stdio.h>
#include <algorithm>
using namespace std;

int n,a[155],b[155];
bool dp[152][151*301];
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a[i],&b[i]);
    }
    dp[1][abs(a[1]-b[1])]=true;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=150*300;j++){
            if(!dp[i-1][j])
            continue;
            dp[i][abs(j+a[i]-b[i])]=dp[i][abs(j-(a[i]-b[i]))]=true;
        }
    }
    for(int i=0;i<=150*300;i++){
        if(dp[n][i]){
            printf("%d",i);
            break;
        }
    }
}