#include <bits/stdc++.h>
using namespace std;

int n,m;
char a[10][10];
string s;
int dx[]={-1,1,0,0},dy[]={0,0,-1,1};

bool f(int x,int y,int k){
    if(k==s.size()) return 1;
    if(x<0||y<0||x>=n||y>=m||a[x][y]!=s[k]) return 0;
    char c=a[x][y];
    a[x][y]='#';
    for(int i=0;i<4;i++)
        if(f(x+dx[i],y+dy[i],k+1)) return 1;
    a[x][y]=c;
    return 0;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    cin>>s;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(f(i,j,0))
                return cout<<"YES",0;

    cout<<"NO";
}