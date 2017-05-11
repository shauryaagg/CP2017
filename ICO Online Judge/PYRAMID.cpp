#include <stdio.h>
#include <algorithm>
using namespace std;
 
int ar[1000005];
int sorar[1000005];
int arr[1000005]={0};
int maxd=0;
int ans=1;
int main() {
    int n;
    scanf("%d",&n);
    int a;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a,&ar[i]);
        ar[i]=min(a,ar[i]);
        maxd=max(maxd,ar[i]);
        arr[ar[i]]++;
    }
    for(int i=1;i<=maxd;i++){
        arr[i]+=arr[i-1];
    }
    for(int i=0;i<n;i++){
        sorar[arr[ar[i]]-1]=ar[i];
        arr[ar[i]]--;
    }
    for(int i=0;i<n;i++){
        if(sorar[i]>=ans){
            ans++;
        }
    }
    printf("%d",ans-1);
    return 0;
}