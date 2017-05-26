#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
int t,m;
ll n,k,s,ans;
ll dp[1000005];
ll rec(ll n){
    if((n<=k)||(n%k==0)) return 1;
    if(dp[n]) return dp[n];
    ll c=0;
    for(ll i=n%k;i<=k;i++){
        c=(c+rec(n-i))%m;
    }
    return dp[n]=c;
}
int main() {
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld%d",&n,&k,&m);
        if(n>1000000) {n%=m;k%=m;}
        for(int i=0;i<=n+2;i++) dp[i]=0;
        if(n%k==0) s=n/k;
        else s=n/k+1;
        printf("%lld %lld\n",s,rec(n));
    }