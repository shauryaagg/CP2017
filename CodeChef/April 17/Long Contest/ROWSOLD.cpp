#include <stdio.h>
#include <string>
using namespace std;
 
int t,c;
long long int ans=0;
char ss[100005];
string s;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%s",ss);
        s=ss;
        s[s.length()]='1';
        c=0;ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1')
            c++;
            else if(s[i+1]=='1')
            ans+=2*c;
            else
            ans+=c;
        }
        printf("%lld\n",ans);
    }
} 