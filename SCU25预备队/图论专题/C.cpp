#include<bits/stdc++.h>
#define pc putchar
#define int long long
using namespace std;
int read()
{
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){f=c=='-'?-1:f;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+(c^48);c=getchar();}
    return x*f;
}
void write(int x)
{
    if(x<0){x=-x;pc('-');}
    if(x>9)write(x/10);
    pc(x%10+48);
}
int n,m,s;
struct edge
{
    int v,w,nxt;
}e[200005];
int head[100005],ecnt=1;
void add(int u,int v,int w)
{
    e[++ecnt].v=v;e[ecnt].w=w;
    e[ecnt].nxt=head[u];
    head[u]=ecnt;
}
priority_queue< pair<int,int> >q;
int dis[100005];
bool vis[100005];
void dk(int s)
{
    memset(dis,0x3f,sizeof dis);
    priority_queue< pair<int,int> >().swap(q);
    memset(vis,false,sizeof vis);
    dis[s]=0;q.push({0,s});
    while(!q.empty())
    {
        int u=q.top().second;q.pop();
        if(vis[u])continue; vis[u]=true;
        for(int i=head[u];i;i=e[i].nxt)
        {
            int v=e[i].v;
            if(dis[v]>dis[u]+e[i].w)
            {
                dis[v]=dis[u]+e[i].w;
                q.push({-dis[v],v});
            }

        }
    }
}

signed main()
{
    n=read(),m=read(),s=read();
    for(int i=1;i<=m;++i)
    {
        int u=read(),v=read(),w=read();
        add(u,v,w);
    }dk(s);
    for(int i=1;i<=n;++i)write(dis[i]),pc(' ');
    return 0;
}