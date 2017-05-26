#include <bits/stdc++.h>
#define inf 9999999
using namespace std;
 
int n,k,p,d,pre[100005];string s;
deque<int>ar,pref;
priority_queue<pair<int,pair<int,int> > >pq;
void kn(){
    int c=0;
    for(int i=0;i<n;i++) c+=ar[i];
    for(int i=0;i<s.length();i++){
        if(s[i]=='?') printf("%d\n",c);
    }
    exit(0);
}
int main() {
    scanf("%d%d%d",&n,&k,&p);
    pre[0]=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&d);
        ar.push_back(d);
        pre[i]=pre[i-1]+ar.back();
    }
    cin>>s;
    if(k>n) kn();
    for(int i=1;i<=n-k+1;i++){
        pref.push_back(pre[i+k-1]-pre[i-1]);
        pq.push(make_pair(pref.back(),make_pair(i-1,0)));
    }
    int w=inf,ind=inf,m=0,ni=0;
    pair<int,pair<int,int> >c;
    for(int i=0;i<s.length();i++){
        while(ind+ni-m>=n-k+1){
            c=pq.top();
            w=c.first;ind=c.second.first;m=c.second.second;
            pq.pop();
        }
        if(s[i]=='?'){ printf("%d\n",w);pq.push(c);}
        else{
            ni++;
            pref.pop_back();
            pref.push_front(ar.back()+pref.front()-ar[k-1]);
            ar.push_front(ar.back());ar.pop_back();
            pq.push(make_pair(w,make_pair(ind+ni-m,ni)));
            pq.push(make_pair(pref.front(),make_pair(0,ni)));
        }
        w=ind=inf;
    }
} 