//HIGHWAY BYPASS
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
int r,c,d;
int ar[301][301];
int mem[301][301][301][2];

int rec(int k, int dir, int i, int j){
    if(i>=r||j>=c||k<0||ar[i][j]==0)
    return 0;
    if(i==r-1&&j==c-1)
    return 1;
    if(mem[i][j][k][dir]>=0){
        return mem[i][j][k][dir];
    }
    else if(dir==1){
        mem[i][j][k][dir]=(rec(k-1,1,i,j+1)+rec(d-1,0,i+1,j))%20011;
        return mem[i][j][k][dir];
    }
    else{
        mem[i][j][k][dir]=(rec(k-1,0,i+1,j)+rec(d-1,1,i,j+1))%20011;
        return mem[i][j][k][dir];
    }
}
int main() {
    cin>>r>>c>>d;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>ar[i][j];
            for(int k=0;k<d;k++){
                for(int l=0;l<2;l++){
                mem[i][j][k][l]=-1;
                }
            }
        }
    }
    if(ar[0][0]==0)
    cout<<0;
    else
    cout<<(rec(d-1,1,0,1)+rec(d-1,0,1,0))%20011;
}