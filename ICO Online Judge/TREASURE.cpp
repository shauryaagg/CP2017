//TREASURE
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

pair<int,int>ar[205][25];
long long int n;
int m,t,s,a,b,d=1,vis[205][25]={0};
pair<int,int> dfs(int m, int t){
    if(d==n)
    return make_pair(m,t);
    if(!vis[m][t])vis[m][t]=d;
    else if(d>1){
        return make_pair(m,t);
    }
    d++;
    return dfs(ar[m][t].first,ar[m][t].second);
}
int dff(int m, int t){
    while(n--){
        a=ar[m][t].first,b=ar[m][t].second;
        m=a;t=b;
    }
    return m;
}
int main(){
    cin>>m>>t>>s>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<t;j++){
            cin>>ar[i][j].second>>ar[i][j].first;
            ar[i][j].second--;ar[i][j].first--;
        }
    }
    a=s-1;b=0;vis[s-1][0]=1;
    pair<int,int> an=dfs(s-1,0);
    vis[s-1][0]=0;
    if(d>=n){
        cout<<an.first+1;
    }
    else{
        d-=vis[an.first][an.second];
        n-=(vis[an.first][an.second]+d);
        n%=d;
        cout<<dff(an.first,an.second)+1;
    }
}