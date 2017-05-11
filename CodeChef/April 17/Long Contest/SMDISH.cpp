#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
 
int t;
string s[4],ss[4];
int main() {
    cin>>t;
    while(t--){
        int c=0;
        for(int i=0;i<4;i++){
            cin>>s[i];
        }
        for(int i=0;i<4;i++){
            cin>>ss[i];
            for(int j=0;j<4;j++){
                if(ss[i]==s[j]){
                    c++;
                    break;
                }
            }
        }
        if(c>=2){
            cout<<"similar\n";
        }
        else{
            cout<<"dissimilar\n";
        }
    }
} 