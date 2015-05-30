\begin{lstlisting}
int n,g[maxn][maxn],mk[maxn],d[maxn],low[maxn];
int color,ti,cutvertexnum,cutvertexlist[maxn];

void dfsvisit(int u,int p)
{
    int v,s=0,bVertex=0; low[u]=d[u]=++ti; mk[u]=-color;
    for(v=1; v<=n; v++) if(g[u][v] && v!=p)
        if(mk[v]==0){ dfsvisit(v,u); s++;
            if(low[v]<low[u]) low[u]=low[v];
            if(low[v]>=d[u]) bVertex=1;
        } else if(d[v]<low[u]) low[u]=d[v];
    if((p && bVertex) || (!p && s>1)) cutvertexlist[cutvertexnum++]=u;
    mk[u]=color;
}

void dfs()
{
    int i,j,k; memset(mk,0,sizeof(mk));
    color=ti=cutvertexnum=0;
    for(i=1; i<=n; i++) if(!mk[i]){ ++color; dfsvisit(i,0); }
    cout<<cutvertexnum<<endl;
    for(i=0;i<cutvertexnum;i++) cout<<cutvertexlist[i]<<" "; cout<<endl;
}
\end{lstlisting}