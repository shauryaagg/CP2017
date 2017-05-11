#include <stdio.h>
#include <math.h>
#include <queue>
#include <vector>
#define ll long long int
using namespace std;
 
ll l,r,ans=0;
bool p[1000005]={false};
vector<ll>pf;
vector<ll>bpf[1000005];
void sieve(){
    for(ll i=2;i<=1000000;i++){
        if(!p[i]){
            pf.push_back(i);
            for(ll j=i*i;j<=1000000;j+=i){
                p[j]=true;
            }
        }
    }
}
void segSieve(){
    for(ll i=0;i<pf.size();i++){
        ll j=(l/pf[i])*pf[i];
        while(j<l){
            j+=pf[i];
        }
        for(;j<=r;j+=pf[i]){
            bpf[j-l].push_back(pf[i]);
        }
    }
}
ll fact(ll n){
    if(n==1)
    return 0;
    ll t=n,c=n,d=1;
    int ct,mct=0;
    priority_queue<ll>pq;
    if(n<=1000000){
        for(int i=0;pf[i]<=sqrt(n)+1;i++){
            ct=0;
            while(t%pf[i]==0){
                t/=pf[i];
                ct++;
            }
            if(ct>0)
            pq.push(ct);
            d*=ct+1;
            if(ct>mct){
                mct=ct;
                c=pf[i];
            }
        }
    }
    else{
        for(int i=0;i<bpf[n-l].size();i++){
            ct=0;
            while(t%bpf[n-l][i]==0){
                t/=bpf[n-l][i];
                ct++;
            }
            if(ct>0)
            pq.push(ct);
            d*=ct+1;
            if(ct>mct){
                mct=ct;
                c=bpf[n-l][i];
            }
        }
    }
    if(t!=1){
        pq.push(1);
        d*=2;
        if(1>mct){
            c=t;
        }
    }
    if(d<=1)d=2;
    n=0;
    while(!pq.empty()){
        n+=d;
        t=pq.top();
        pq.pop();
        d/=t+1;
        d*=t;
        if(t-1>0)
        pq.push(t-1);
    }
    return n;
}
int main() {
    scanf("%lld%lld",&l,&r);
    sieve();
    if(r>1000000)segSieve();
    while(l<=r){
        ans+=fact(r--);
    }
    printf("%lld",ans);
} 