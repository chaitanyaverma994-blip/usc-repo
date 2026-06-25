#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> b;
vector<int> c, d1, d2;
bool ok;

void f(int r){
    if(r==n){
        ok=1;
        for(auto &x:b) cout<<x<<"\n";
        return;
    }
    for(int i=0;i<n;i++){
        if(c[i]||d1[r-i+n-1]||d2[r+i]) continue;
        b[r][i]='Q';
        c[i]=d1[r-i+n-1]=d2[r+i]=1;
        f(r+1);
        b[r][i]='.';
        c[i]=d1[r-i+n-1]=d2[r+i]=0;
    }
}

int main(){
    cin>>n;
    b.assign(n,string(n,'.'));
    c.assign(n,0);
    d1.assign(2*n,0);
    d2.assign(2*n,0);

    f(0);

    if(!ok) cout<<-1;
}