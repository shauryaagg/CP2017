//TFINDPERM
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

vector<int>a;
int n;
int ar[100005];
int main() {
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ar[i];
        a.insert(a.end()-ar[i],i+1);
    }
    for(int i=0;i<a.size();i++)
    cout<<a[i]<<" ";
}