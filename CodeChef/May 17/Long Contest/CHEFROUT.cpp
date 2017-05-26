#include <bits/stdc++.h>
using namespace std;
 
int t,c,i;
string s;
int main() {
    scanf("%d",&t);
    while(t--){
        cin>>s;
        c=0;
        for(i=0;i<s.length();i++){
            if(s[i]=='C'&&c<=1) c=1;
            else if(s[i]=='E'&&c<=2) c=2;
            else if(s[i]=='S'&&c<=3) c=3;
            else break;
        }
        if(i<s.length()) printf("no\n");
        else printf("yes\n");
    }
} 