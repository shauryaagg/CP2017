#include <stdio.h>
using namespace std;
int main()
{
    long long int n,flag=0;
    int k,tmp=0;
    scanf("%lld%d",&n,&k);
    int *ar=new int[k];
    for(int i=0;i<k;i++){
        scanf("%d",&ar[i]);
    }
    for(int i=0;i<k;i++){
        for(int j=1;j<=n;j+=ar[i]){
            tmp=0;
            for(int l=0;l<i;l++){
                if(((j-1)%ar[l])==0){tmp=1;
                break;
                }
            }
            if(tmp==0)
            flag++;
        }
    }
    printf("%lld",(n-flag));
}
 