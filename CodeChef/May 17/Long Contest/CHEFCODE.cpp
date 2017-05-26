#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
ll n,d; int leng=0,len=0;
long double k,dd=0;
vector<long double>ar;
long double pref[35];
ll fast_exp(ll base, ll exp) {
    ll res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base);
       base=(base*base);
       exp/=2;
    }
    return res;
}
ll rec(ll bitmask){
    if(bitmask>=((ll)1<<n)) return 0;
    long double res=0;
    int l=0;
    for(ll i=0;i<n;i++){
        if(((ll)1<<i)&bitmask){
            l++;
            if(res+ar[i]<=k){
                res+=ar[i];
            }
            else return 0;
        }
    }
    ll c=1;
    int b=30;
    for(;b>=0;b--){
        if(((ll)1<<b)&bitmask){
            break;
        }
    }ll f;
    if(l<leng)
    for(ll i=b+1;i<n;i++){
        f=rec(bitmask|((ll)1<<i));
        if(!f) break;
        c+=f;
    }
    return c;
}
ll empty(ll bitmask){
    if(bitmask>=((ll)1<<n)) return 0;
    long double res=0;
    for(ll i=0;i<n;i++){
        if(((ll)1<<i)&bitmask){
            res+=ar[i];
        }
    }
    ll c=0,f,b;
    for(b=0;b<n;b++){
        if(bitmask&(1<<b))break;
    }
    if(res>k)return fast_exp(2,b);
    if(bitmask==0)b=n;
    for(ll i=b-1;i>=0;i--){
        f=empty(bitmask|((ll)1<<i));
        if(!f) break;
        c+=f;
    }
    return c;
}
int main() {
    scanf("%lld%lld",&n,&d);k=log10(d);
    for(int i=0;i<n;i++){
        scanf("%lld",&d);
        if((long double)log10(d)<=k){ ar.push_back(log10(d));dd+=ar.back();}
    }
    n=ar.size();
    if(dd<=k) printf("%lld",(fast_exp(2,n)-1));
    else{
        sort(ar.begin(),ar.end());
        leng=1;dd=ar[0];
        for(int i=1;i<ar.size();i++){
            dd+=ar[i];
            if(dd<=k)leng++;
            else break;
        }
        if(leng<=n/2+1)
        printf("%lld",rec(0)-1);
        else
        printf("%lld",fast_exp(2,n)-empty(0)-1);
    }
}   