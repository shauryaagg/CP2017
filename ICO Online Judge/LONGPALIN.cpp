//LONGPALING
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int n;
int ans=0;
bool dp[5005][5005];
char ar[5005];
int main() {
    cin>>n;
    memset(dp,false,sizeof(dp));
    for(int i=1;i<=n;i++){
        cin>>ar[i];
        dp[i][i]=true;
    }
    for(int i=1;i<n;i++){
        if(ar[i]==ar[i+1])
        dp[i][i+1]=true;
    }
    for(int k=2;k<=n;k++){
        for(int i=1;i<=n;i++){
            if(ar[i]==ar[i+k]&&dp[i+1][i+k-1]){
                dp[i][i+k]=true;
                ans=k;
            }
        }
    }
    cout<<ans+1<<endl;
    for(int i=1;i<=n;i++){
        if(dp[i][i+ans]){
            for(int j=i;j<=i+ans;j++){
                cout<<ar[j];
            }
        }
    }
}