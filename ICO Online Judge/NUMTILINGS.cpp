#include <iostream>
using namespace std;

int n,dp[1000005][5];
int main() {
    cin>>n;
    dp[0][2]=1;
    dp[0][1]=0;
    dp[1][2]=1;
    dp[1][1]=1;
    for(int i=2;i<=n;i++){
        dp[i][2]=(dp[i-1][2]+dp[i-2][2]+dp[i-2][1]*2)%10000;
        dp[i][1]=(dp[i-1][2]+dp[i-1][1])%10000;
    }
    cout<<dp[n][2];
    return 0;
}
