\begin{lstlisting}
#define maxn 1000
#define maxm 2*maxn*maxn

int c[maxm],f[maxm],ev[maxm],be[maxm],next[maxm],num=0;
int nbs[maxn],pnt[maxn],open[maxn],d[maxn],mk[maxn];

void AddEdge(int u,int v,int cc) // Remember to set nbs[1..n]=num=0
{
    next[++num]=nbs[u];    nbs[u]=num; be[num]=num+1;
    ev[num]=v; c[num]=cc;  f[num]=0; 
    next[++num]=nbs[v];    nbs[v]=num; be[num]=num-1;
    ev[num]=u; c[num]=0 ;  f[num]=0;
}

int maxflow(int n,int s,int t)
{
    int cur,tail,i,j,u,v,flow=0; // f has been set zero when AddEdge
    do{ memset(mk,0,sizeof(mk));  memset(d,0,sizeof(d));
        open[0]=s; mk[s]=1; d[s]=0x3fffffff;
        for(pnt[s]=cur=tail=0; cur<=tail && !mk[t]; cur++)
            for(u=open[cur],j=nbs[u];j;j=next[j]) { v=ev[j];
                if(!mk[v]&&f[j]<c[j]){
                    mk[v]=1; open[++tail]=v; pnt[v]=j;
                    if(d[u]<c[j]-f[j]) d[v]=d[u]; else d[v]=c[j]-f[j];
                }
            }               
        if(!mk[t]) break; flow+=d[t];
        for(u=t;u!=s;u=ev[be[j]]){j=pnt[u];f[j]+=d[t];f[be[j]]=-f[j];}
    } while(d[t]>0); return flow;
}
\end{lstlisting}
