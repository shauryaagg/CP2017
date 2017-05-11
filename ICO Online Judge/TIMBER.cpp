//TIMBER
#include <stdio.h>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
using namespace std;
 
int n,m,c;
int ar[1005][1005];
int area[1005][1005]={0};
int row;
int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        row=0;
        for(int j=1;j<=m;j++){
            scanf("%d",&ar[i][j]);
            row+=ar[i][j];
            area[i][j]=area[i-1][j]+row;
        }
    }
    scanf("%d",&c);
    int a,b,e,d;
    int x1,y1,x2,y2;
    while(c--){
        scanf("%d%d%d%d",&a,&b,&e,&d);
        x2=max(a,e);
        y2=max(b,d);
        x1=min(a,e);
        y1=min(b,d);
        printf("%d\n",area[x2][y2]-area[x2][y1-1]-area[x1-1][y2]+area[x1-1][y1-1]);
    }
}