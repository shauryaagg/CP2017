#include <bits/stdc++.h>
using namespace std;

int n;
char s[105][20];
vector<int>ar[100];
bool del(string a, string b){
    for(int i=0;i<a.length();i++){
        if((a.substr(0,i)+a.substr(i+1))==b)
        return true;
    }
    return false;
}
bool rep(string a, string b){
    for(int i=0;i<a.length();i++){
        for(int j=i+1;j<a.length();j++){
            if((a[j]>a[i])&&(a.substr(0,i)+a[j]+a.substr(i+1))==b)
            return true;
        }
    }
    return false;
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",s[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j&&(rep(s[i],s[j])||del(s[i],s[j]))){
                ar[i].push_back(j);
            }
        }
    }
    queue<int>q;
    int maxdep=1;
    for(int i=0;i<n;i++){
        q.push(i);
        int dep[n+5];
        dep[i]=1;
        while(!q.empty()){
            int f=q.front();
            q.pop();
            for(int j=0;j<ar[f].size();j++){
                q.push(ar[f][j]);
                dep[ar[f][j]]=dep[f]+1;
                maxdep=max(maxdep,dep[ar[f][j]]);
            }
        }
    }
    printf("%d",maxdep);
}