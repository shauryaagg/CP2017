#include <bits/stdc++.h>
using namespace std;
 
int t,i,j;
vector<string>add,del,ans;
string s;
char c;
bool lcomp(string a, string b){
    for(int i=0;i<min(a.length(),b.length());i++){
        if(a[i]==b[i]) continue;
        else return a[i]<b[i];
    }
    if(b.length()<=a.length()) return false;
    else return true;
}
bool comp(string a, string b){
    for(int i=0;i<min(a.length(),b.length());i++){
        if(a[i]==b[i]) continue;
        else return a[i]<b[i];
    }
    return false;
}
bool ucomp(string a, string b){
    for(int i=0;i<min(a.length(),b.length());i++){
        if(a[i]==b[i]) continue;
        else return a[i]<b[i];
    }
    return false;
}
int main() {
    scanf("%d",&t);
    while(t--){
        scanf(" %c",&c);
        cin>>s;
        if(c=='+') add.push_back(s);
        else del.push_back(s);
    }
    sort(add.begin(),add.end());
    for(i=0;i<del.size();i++){
        string c="";
        for(j=0;j<del[i].length();j++){
            c+=del[i][j];
            if(lower_bound(add.begin(),add.end(),c,lcomp)==upper_bound(add.begin(),add.end(),c,ucomp)) break;
        }
        if(j==del[i].length()){printf("-1");return 0;}
        else ans.push_back(c);
    }
    sort(ans.begin(),ans.end());
    int size=ans.size();
    for(int i=0;i<ans.size()-1;i++){
        string c=ans[i];
        ans[i]=ans[i+1];
        if(lower_bound(ans.begin()+i+1,ans.end(),c,comp)==upper_bound(ans.begin()+i+1,ans.end(),c,comp)){
            ans[i]=c;
        }
        else{
            ans[i]="XX";
            size--;
        }
    }
    printf("%d\n",size);
    for(i=0;i<ans.size();i++) if(ans[i]!="XX")cout<<ans[i]<<"\n";
} 