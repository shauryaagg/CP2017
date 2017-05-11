//PERIODIC STRINGS
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int>pf;
int n,m;
void primeFactors(int n){
    if(n%2==0)
    pf.push_back(2);
     while (n%2 == 0)
    {
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
        if(n%i==0)
        pf.push_back(i);
        while (n%i == 0)
        {
            n = n/i;
        }
    }
    if(n>2)
    pf.push_back(n);
 
}
int power(int p){
    int d=1;
    for(int i=1;i<=p;i++){
        d*=2;
        d%=m;
    }
    return d-2<0?d-2+m:d-2;
}
int main(){
    cin>>n>>m;
    primeFactors(n);
    int a=0;
    for(int i=0;i<pf.size();i++){
        if(pf[i]==n)continue;
        a+=power(pf[i]);
        cout<<a<<" ";
        a%=m;
    }
    a+=2;
    a%=m;
    int ans=power(n)+2-a;
    ans+=(ans<0?m:0);
    cout<<ans;
}