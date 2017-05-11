//DEVIOUS
#include <stdio.h>
#include <algorithm>
using namespace std;
 
int n,ar[100005],ans=99999999,a=1,b=1,tmp;
pair<int,int>pre[100005];
int main() {
    scanf("%d",&n);
    pre[0].first=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&ar[i]);
        if(abs(ar[i])<abs(ans)){
            ans=ar[i];
            a=i;b=i;
        }
        pre[i].first=ar[i]+pre[i-1].first;
        pre[i].second=i;
        if(abs(ans)>=abs(pre[i].first)){
            ans=pre[i].first;
            a=1;
            b=pre[i].second;
        }
    }
    sort(pre+1,pre+n+1);
    for(int i=2;i<=n;i++){
        if(abs(pre[i].first-pre[i-1].first)<abs(ans)){
            if(pre[i-1].second<pre[i].second){
                ans=pre[i].first-pre[i-1].first;
                a=pre[i-1].second+1;
                b=pre[i].second;
            }
            else{
                ans=pre[i-1].first-pre[i].first;
                a=pre[i].second+1;
                b=pre[i-1].second;
            }
        }
        else if(abs(pre[i].first-pre[i-1].first)==abs(ans)&&abs(pre[i].second-pre[i-1].second)>b-a){
            if(pre[i-1].second<pre[i].second){
                ans=pre[i].first-pre[i-1].first;
                a=pre[i-1].second+1;
                b=pre[i].second;
            }
            else{
                ans=pre[i-1].first-pre[i].first;
                a=pre[i].second+1;
                b=pre[i-1].second;
            }
        }
    }
    printf("%d\n%d %d",ans,a,b);
}