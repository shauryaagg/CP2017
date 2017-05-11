#include <bits/stdc++.h>
using namespace std;

int n,d;
vector<vector<int> >ar;
int main() {
    scanf("%d",&n);
    ar.resize(n);
    for(int i=0;i<n;i++){
        scanf("%d",&d);
        while(d!=-1){
            ar[i].push_back(d);
            scanf("%d",&d);
        }
    }
    sort(ar.begin(),ar.end());
    for(int i=0;i<n;i++){
        for(int j=0;j<ar[i].size();j++){
            printf("%d ",ar[i][j]);
        }printf("\n");
    }
}