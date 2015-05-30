\begin{lstlisting}
int nx,ny,m, g[MAXN][MAXN],sy[MAXN],cx[MAXN],cy[MAXN];
    
int path(int u)
{
    for(int v=1;v<=ny;v++) if(g[u][v] && !sy[v]){ sy[v]=1;
        if(!cy[v] || path(cy[v])) { cx[u]=v; cy[v]=u; return 1;}
    } return 0; 
}

int MaximumMatch()
{
    int i,ret=0;
    memset(cx,0,sizeof(cx)); memset(cy,0,sizeof(cy));
    for(i=1;i<=nx;i++)if(!cx[i]){memset(sy,0,sizeof(sy));ret+=path(i);}
    return ret;
}
\end{lstlisting}
