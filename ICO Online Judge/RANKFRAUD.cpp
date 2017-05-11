//RANKFRAUD
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<int> >ar;
bool vis[2005];
list<int>q;
int n;
int a,m;
void dfs(int node, int md){
    if(vis[node])return;
    if(a==n||md==n){
        a=n;
        q.push_front(node+1);
        return;
    }
    vis[node]=true;
    for(int i=0;i<ar[node].size();i++){
        dfs(ar[node][i],md+1);
        if(a==n){
            a=n;
            q.push_front(node+1);
            return;
        }
    }
    vis[node]=false;
}
int main() {
    cin>>n;
    ar.resize(n);
    for(int i=0;i<n;i++){
        cin>>m;
        for(int j=0;j<m;j++){
            cin>>a;
            ar[i].push_back(a-1);
        }
    }
    for(int i=0;i<n;i++){
        memset(vis,false,n+1);
        a=0;
        dfs(i,1);
        if(a==n){
            cout<<"YES\n";
            while(!q.empty()){
                cout<<q.front()<<" ";
                q.pop_front();
            }
            exit(0);
        }
    }
    cout<<"NO";
    
}