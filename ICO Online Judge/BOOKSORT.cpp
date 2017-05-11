#include <bits/stdc++.h>
using namespace std;

int n,d;
int dp[200005];
int main() {
    scanf("%d",&n);
    int l=0;
    dp[0]=-9999999;
    for(int i=1;i<=n;i++){
        scanf("%d",&d);
        if(d>dp[l]){
            l++;
            dp[l]=d;
        }
        else if(d<dp[1]){
            dp[1]=d;
        }
        else{
            dp[upper_bound(dp+1,dp+l+1,d)-dp]=d;
        }
    }
    printf("%d",n-l);
}