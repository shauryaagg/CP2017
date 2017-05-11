#include <bits/stdc++.h>
using namespace std;

int n,d;
priority_queue<int>pq;
int main(){
    scanf("%d%d",&n,&d);n+=d;
    while(n--){
        scanf("%d",&d);
        if(d==-1){
            printf("%d\n",pq.top());
            pq.pop();
        }
        else pq.push(d);
    }
}