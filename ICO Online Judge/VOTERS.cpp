//VOTERS
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    vector<int>v;
    int a[n1],b[n2],c[n3];
    for(int i=0;i<n1;i++){
        cin>>a[i];
    }
    for(int i=0;i<n2;i++){
        cin>>b[i];
    }
    for(int i=0;i<n3;i++){
        cin>>c[i];
    }
    sort(a,a+n1);
    sort(b,b+n2);
    sort(c,c+n3);
    for(int i=0;i<n1;i++){
        if(binary_search(b,b+n2,a[i])||binary_search(c,c+n3,a[i])){
            if(!binary_search(v.begin(),v.end(),a[i])){
                v.insert(upper_bound(v.begin(),v.end(),a[i]),a[i]);
            }
        }
    }
    for(int i=0;i<n2;i++){
        if(binary_search(a,a+n1,b[i])||binary_search(c,c+n3,b[i])){
            if(!binary_search(v.begin(),v.end(),b[i]))
            v.insert(upper_bound(v.begin(),v.end(),b[i]),b[i]);
        }
    }
    for(int i=0;i<n3;i++){
        if(binary_search(a,a+n1,c[i])||binary_search(b,b+n2,c[i])){
            if(!binary_search(v.begin(),v.end(),c[i]))
            v.insert(upper_bound(v.begin(),v.end(),c[i]),c[i]);
        }
    }
    sort(v.begin(),v.end());
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
}