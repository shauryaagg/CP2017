//EXPERIMENT
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int a[305];
int b[305];
int n;
int ans[305][2];
map<int,int>mymap;
int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int m=0;
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(++mymap[a[i]-b[j]]>m){
                m=mymap[a[i]-b[j]];
                k=a[i]-b[j];
            }
        }
    }
    cout<<m<<endl;
    int l=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i]-b[j]==k){
                ans[l][0]=a[i];
                ans[l][1]=b[j];
                l++;
            }
        }
    }
    for(int i=0;i<l;i++){
        cout<<ans[i][0]<<" ";
    }
    cout<<endl;
    for(int i=0;i<l;i++){
        cout<<ans[i][1]<<" ";
    }
}