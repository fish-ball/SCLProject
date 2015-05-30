\begin{lstlisting}
int n,g[maxn][maxn],mk[maxn],d[maxn],low[maxn];
int color,ti,bridgenum,bridgeu[maxn],bridgev[maxn];

void dfsvisit(int u,int p)
{
    int v,s=0,bBridge=0; low[u]=d[u]=++ti; mk[u]=-color;
    for(v=1; v<=n; v++) if(g[u][v] && v!=p)
        if(mk[v]==0){ dfsvisit(v,u); s++;
            if(low[v]<low[u]) low[u]=low[v];
            if(low[v]==d[v]) {
                bridgeu[bridgenum  ]=u;
                bridgev[bridgenum++]=v;
            }
        } else if(d[v]<low[u]) low[u]=d[v];
    mk[u]=color;
}

void dfs()
{
    int i,j,k; memset(mk,0,sizeof(mk));
    color=ti=bridgenum=0;
    for(i=1; i<=n; i++) if(!mk[i]){ ++color; dfsvisit(i,0); }
    cout<<bridgenum<<endl;
}
\end{lstlisting}