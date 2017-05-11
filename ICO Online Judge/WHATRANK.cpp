//WHATRANK
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> v;
    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
        cout<<(i+1)-(upper_bound(v.begin(),v.end(),ar[i])-v.begin())<<endl;
        v.insert((upper_bound(v.begin(),v.end(),ar[i])),ar[i]);
    }
}