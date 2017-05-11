//RAILCATER
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

int ar[1000005];
int sub[1000005];
int states[1000005];
int main() {
    int n,k;
    cin>>n>>k;
    sub[0]=0;
    for(int i=0;i<n;i++){
        cin>>ar[i];
        sub[i+1]=ar[i]+sub[i];
    }
    int ans=sub[n];
    states[k]=sub[k];
    for(int i=k+1;i<=n;i++){
        states[i]=max(ar[i-1]+states[i-1],sub[i]-sub[i-k]);
        ans=max(states[i],ans);
    }
    cout<<ans;
}
