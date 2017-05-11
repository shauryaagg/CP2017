//CYCLEPERM
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

int n,k=0,ar[1005];
bool vis[1005],f=false;
vector<vector<int> >v(1005);
int main() {
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ar[i];
    }
    for(int i=1;i<=n;i=ar[i]){
        if(vis[i]){
            v[k].push_back(i);k++;
            for(int j=1;j<=n;j++){
                if(!vis[j]){
                    i=j;
                    break;
                }
                if(j==n){
                    f=true;
                }
            }
        }
        if(f)
        break;
        vis[i]=true;
        v[k].push_back(i);
    }
    cout<<k<<"\n";
    for(int i=0;i<k;i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }cout<<"\n";
    }
}