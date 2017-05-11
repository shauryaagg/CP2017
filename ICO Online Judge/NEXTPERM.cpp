//NEXT_PERM
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

int n,k;
int ar[1005];
int main() {
    cin>>n>>k;
    while(k--){
        for(int i=0;i<n;i++){
            cin>>ar[i];
        }
        next_permutation(ar,ar+n);
        for(int i=0;i<n;i++){
            cout<<ar[i]<<" ";
        }
        cout<<"\n";
    }
}