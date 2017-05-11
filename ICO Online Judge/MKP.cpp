#include <bits/stdc++.h>
using namespace std;

string s;
int main() {
    cin>>s;
    int i=0;
    bool f=false,c=false;
    while(i<=s.length()-i-1){
        if(!f&&s[i]!=s[s.length()-i-1]){
            f=true;
            c=true;
        }
        else if(s[i]!=s[s.length()-i-1]){
            c=false;
            break;
        }
        i++;
    }
    if(c||s.length()&1)printf("YES");
    else printf("NO");
}