#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int k,n,ar[25];
int gcd(int a, int b){
    if(!(a%b)) return b;
    return gcd(b,a%b);
}
ll lcm(int a, int b){
    return ((ll)a*b)/gcd(max(a,b),min(a,b));
}
int rec(int i, bool add, ll lc){
    if(i>k||lc>n) return 0;
    ll newlc=lcm(lc,ar[i]);
    int c=n/newlc;
    if(!add)c=-c;
    c+=rec(i+1,!add,newlc)+rec(i+1,add,lc);
    return c;
}
int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++){
        scanf("%d",&ar[i]);
    }n--;
    printf("%d",n-rec(1,true,1));
}