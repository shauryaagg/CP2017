//REVERSE
#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

int n;
string s,ss,ar[10005];
bool f=false;
int main(){
    cin>>n;
    getline(cin,s);
    for(int i=1;i<=n;i++){
        getline(cin,s);
        f=false;
        ss="";
        string d="";
        for(int j=s.length()-1;j>=0;j--){
            if(s[j]==','||s[j]=='.'||s[j]==':'||s[j]==';'||s[j]==39||s[j]==' '){
                f=true;
                continue;
            }
            if(f){
                if(!ss.empty())
                ss=ss+" "+d;
                else
                ss=d;
                d=s[j];
                f=false;
            }
            else{
                d=s[j]+d;
            }
        }
        ss=ss+" "+d;
        ar[i]=ss;
    }
    for(int i=n;i>=1;i--){
        cout<<ar[i]<<"\n";
    }
}