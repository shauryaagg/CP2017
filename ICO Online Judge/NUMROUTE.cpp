//NUMROUTE
#include <stdio.h>
#define M 42373
using namespace std;

int n,s,t,ar[150][150],org[150][150];
long long int k;
void mmul(long long int e){
    if(e==1){
        return;
    }
    long long int a;
    int t[150][150]={{0}},cop[150][150];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cop[i][j]=org[i][j];
        }
    }
    for(a=1;a*2<=e;a*=2){
        for(int l=0;l<n;l++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    t[l][i]+=cop[l][j]*cop[j][i];
                    t[l][i]%=M;
                }
            }
        }   
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cop[i][j]=t[i][j];
                t[i][j]=0;
            }
        }
    }
    if(e>a){
        mmul(e-a);
        for(int l=0;l<n;l++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    t[l][i]+=cop[l][j]*ar[j][i];
                    t[l][i]%=M;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cop[i][j]=t[i][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ar[i][j]=cop[i][j];
        }
    }
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&org[i][j]);
            ar[i][j]=org[i][j];
        }
    }
    scanf("%d%d%lld",&s,&t,&k);
    if(k!=0){
        mmul(k);
        printf("%d",ar[s-1][t-1]);
    }
    else if(s==t){
        printf("%d",1);
    }
    else{
        printf("%d",0);
    }
    
}