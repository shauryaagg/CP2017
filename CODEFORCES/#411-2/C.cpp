#include <bits/stdc++.h>
using namespace std;

int n;
int main() {
    scanf("%d",&n);
    if(n&1) printf("%d",(n-1)/2);
    else printf("%d",n/2-1);
}