#include <bits/stdc++.h>
#define M 1000000007
#define ll long long int
using namespace std;

char s[1000005];
ll ans=0,b=0;
int main() {
    scanf("%s",s);
    for(int i=strlen(s)-1;i>=0;i--){
        if(s[i]=='b')b=(b+1)%M;
        else {ans=(ans+b)%M;b=(b<<1)%M;}
    }
    cout<<ans;
}