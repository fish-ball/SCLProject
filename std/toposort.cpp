\begin{lstlisting}
int n,mk[maxn],topo[maxn],g[maxn][maxn],ps,topook;

void dfs(int u)
{
    if(mk[u]<0){topook=0; return;}; if(mk[u]>0) return; else mk[u]=-1;
    for(int v=1; topook && v<=n; v++) if(g[u][v]) dfs(v);       
    topo[ps--]=u; mk[u]=1;
}

void toposort()
{
    int i,j,k; topook=1; ps=n; memset(mk,0,sizeof(mk));
    for(i=1;topook && i<=n;i++) if(!mk[i]) dfs(i);
}

int main()
{
    int i,m,u,v;
    while(cin>>n>>m,n && !cin.fail()){
        memset(g,0,sizeof(g));
        while(m--){ cin>>u>>v; g[u][v]=1; }; toposort();
        for(i=1;i<n;i++) cout<<topo[i]<<" "; cout<<topo[n]<<endl;
    }   
    return 0;
}
\end{lstlisting}
