#include<bits/stdc++.h>
#define pc putchar
using namespace std;
int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){f=c=='-'?-1:f;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+(c^48);c=getchar();}
    return x*f;
}
void write(int x){
    if(x<0){x=-x;pc('-');}
    if(x>9)write(x/10);
    pc(x%10+48);
}
int n,m,tx,ty;
bool vis[405][405];
int res[405][405];
queue< pair<int,int> >q;
int dir[8][2]={{-2,1},{-2,-1},{2,-1},{2,1},{-1,-2},{-1,2},{1,-2},{1,2}};
int main(){
    n=read(),m=read(),tx=read(),ty=read();
    q.push({tx,ty});vis[tx][ty]=true;
    for(int i=1;i<=n;++i)fill(res[i]+1,res[i]+m+1,-1);
    res[tx][ty]=0;
    while(!q.empty()){
        int x=q.front().first,y=q.front().second;q.pop();
        for(int i=0;i<8;++i)
        {
            int dx=x+dir[i][0],dy=y+dir[i][1];
            if(dx<1||dx>n||dy<1||dy>m)continue;
            if(vis[dx][dy])continue;
            res[dx][dy]=res[x][y]+1;vis[dx][dy]=true;
            q.push({dx,dy});
        }
    }
    for(int i=1;i<=n;++i,pc('\n'))
        for(int j=1;j<=m;++j)
            write(res[i][j]),pc(' ');
    return 0;
}